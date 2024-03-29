// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';

var Fs = require("fs");
var $$Array = require("bs-platform/lib/js/array.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Caml_int32 = require("bs-platform/lib/js/caml_int32.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

function processInput(values, index) {
  var result = values;
  var operation = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 0 | 0));
  if (operation === 99) {
    result = result;
  } else {
    var firstInput = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 1 | 0))));
    var secondInput = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 2 | 0))));
    var outputPosition = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 3 | 0));
    if (operation === 1) {
      Caml_array.caml_array_set(result, outputPosition, String(firstInput + secondInput | 0));
      result = processInput(result, index + 4 | 0);
    }
    if (operation === 2) {
      Caml_array.caml_array_set(result, outputPosition, String(Caml_int32.imul(firstInput, secondInput)));
      result = processInput(result, index + 4 | 0);
    }
    
  }
  return result;
}

function main(input) {
  var values = input.split(",");
  Caml_array.caml_array_set(values, 1, "12");
  Caml_array.caml_array_set(values, 2, "2");
  var result = processInput(values, 0);
  return Caml_array.caml_array_get(result, 0);
}

var Part1 = {
  processInput: processInput,
  main: main
};

function processInput$1(input, index, noun, verb) {
  var values = $$Array.of_list(input);
  Caml_array.caml_array_set(values, 1, noun);
  Caml_array.caml_array_set(values, 2, verb);
  var result = values;
  var operation = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 0 | 0));
  if (operation === 99) {
    result = result;
  } else {
    var firstInput = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 1 | 0))));
    var secondInput = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 2 | 0))));
    var outputPosition = Caml_format.caml_int_of_string(Caml_array.caml_array_get(values, index + 3 | 0));
    if (operation === 1) {
      Caml_array.caml_array_set(result, outputPosition, String(firstInput + secondInput | 0));
      result = processInput$1($$Array.to_list(result), index + 4 | 0, noun, verb);
    }
    if (operation === 2) {
      Caml_array.caml_array_set(result, outputPosition, String(Caml_int32.imul(firstInput, secondInput)));
      result = processInput$1($$Array.to_list(result), index + 4 | 0, noun, verb);
    }
    
  }
  return result;
}

function main$1(input) {
  var values = input.split(",");
  var result = /* record */[/* contents */values];
  for(var i = 0; i <= 99; ++i){
    for(var j = 0; j <= 99; ++j){
      result[0] = processInput$1($$Array.to_list(values), 0, String(i), String(j));
      if (Caml_array.caml_array_get(result[0], 0) === "19690720") {
        console.log(Caml_int32.imul(100, i) + j | 0);
      }
      
    }
  }
  return result;
}

var Part2 = {
  processInput: processInput$1,
  main: main$1
};

var Day02 = {
  Part1: Part1,
  Part2: Part2
};

var file = Fs.readFileSync("./input.txt", "utf8");

console.log(main(file));

console.log(main$1(file));

exports.Day02 = Day02;
exports.file = file;
/* file Not a pure module */
