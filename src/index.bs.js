// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Express = require("express");
var $$Request = require("request");

var objectRequest = {
  url: "https://swapi.co/api/films"
};

var app = Express();

app.get("/", (function (param, res) {
        res.send({
              statusCode: 200,
              message: "A simple BFF with ReasonML"
            });
        return /* () */0;
      }));

app.get("/films", (function (param, res) {
        $$Request(objectRequest, (function (error, response, body) {
                if (error || response.statusCode !== 200) {
                  res.send({
                        statusCode: 400,
                        message: "Unable to make the request"
                      });
                }
                res.send(body);
                return /* () */0;
              }));
        return /* () */0;
      }));

app.listen(5000);

exports.objectRequest = objectRequest;
exports.app = app;
/* app Not a pure module */
