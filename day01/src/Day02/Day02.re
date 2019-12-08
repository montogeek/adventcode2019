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
};

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Day02.Part1.main(file)->Js.log;