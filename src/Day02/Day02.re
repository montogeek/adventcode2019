module Day02 = {
  module Part1 = {
    let rec processInput = (values, index) => {
      let result = ref(values);

      let operation = int_of_string(values[index + 0]);

      if (operation === 99) {
        result := result^;
      } else {
        let firstInput =
          int_of_string(values[int_of_string(values[index + 1])]);
        let secondInput =
          int_of_string(values[int_of_string(values[index + 2])]);
        let outputPosition = int_of_string(values[index + 3]);

        if (operation === 1) {
          result^[outputPosition] = string_of_int(firstInput + secondInput);
          result := processInput(result^, index + 4);
        };

        if (operation === 2) {
          result^[outputPosition] = string_of_int(firstInput * secondInput);
          result := processInput(result^, index + 4);
        };
      };

      result^;
    };

    let main = input => {
      let values = Js.String.split(",", input);
      values[1] = "12";
      values[2] = "2";
      let result = processInput(values, 0);
      result[0];
    };
  };

  module Part2 = {
    let rec processInput = (input, index, noun, verb) => {
      let values = Array.of_list(input)
      values[1] = noun;
      values[2] = verb;
      let result = ref(values);

      let operation = int_of_string(values[index + 0]);

      if (operation === 99) {
        result := result^;
      } else {
        let firstInput =
          int_of_string(values[int_of_string(values[index + 1])]);
        let secondInput =
          int_of_string(values[int_of_string(values[index + 2])]);
        let outputPosition = int_of_string(values[index + 3]);

        if (operation === 1) {
          result^[outputPosition] = string_of_int(firstInput + secondInput);
          result := processInput(Array.to_list(result^), index + 4, noun, verb);
        };

        if (operation === 2) {
          result^[outputPosition] = string_of_int(firstInput * secondInput);
          result := processInput(Array.to_list(result^), index + 4, noun, verb);
        };
      };

      result^;
    };

    let main = input => {
      let values = Js.String.split(",", input);
      let result = ref(values);
      let goal = "19690720";

      for (i in 0 to 99) {
        for (j in 0 to 99) {
          result :=
            processInput(Array.to_list(values), 0, string_of_int(i), string_of_int(j));

          if (result^[0] === goal) {
            Js.log(100 * i + j);
          };
        };
      };
      result;
    };
  };
};

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Day02.Part1.main(file)->Js.log
Day02.Part2.main(file)->Js.log;