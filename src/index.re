type express;
type request;
type response;
type body;
type handler = (string, response) => unit;

type responseRequest = {
  statusCode: int,
  message: string,
};

type requestParam = {
  url: string,
};

type handlerRequest = (bool, responseRequest, body) => unit;

[@bs.module] external express : unit => express = "express";
[@bs.module] external request : (requestParam, handlerRequest) => unit = "request";
[@bs.send] external get : (express, string, handler) => unit = "get";
[@bs.send] external send : (response, responseRequest) => unit = "send";
[@bs.send] external sendRequestBody : (response, body) => unit = "send";
[@bs.send] external listen : (express, int) => unit = "listen";

let objectRequest = {url:"https://swapi.co/api/films"};

let app = express();

get(app, "/", (_, res) => {
  let response = {statusCode:200, message:"A simple BFF with ReasonML"};
  send(res, response);
});

get(app, "/films", (_, res) => {
  request(objectRequest, (error, response, body) => {
    if(error || response.statusCode !== 200) {
      let errorResponse = {statusCode:400, message:"Unable to make the request"};
      send(res, errorResponse);
    }
    sendRequestBody(res, body);
  })
});

listen(app, 5000)
