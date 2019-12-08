module type Day01T = {let getTotalFuel: string => int;};

// module Day01: Day01T = {
  let splitLines = lines => Js.String.split("\n", lines);
  let toIntegers = strings => Js.Array.map(int_of_string, strings);
  let calculateFuel = masses =>
    Js.Array.map(
      mass => Js.Math.floor(Js.Int.toFloat(mass / 3)) - 2,
      masses,
    );

  let calculateTotalFuel = fuels =>
    Js.Array.reduce((a, b) => a + b, 0, fuels);

  let calTotalfuel = fuels => Array.fold_left((a, b) => a + b, 0, fuels);

  let getTotalFuel = input => {
    let totalFuel = input->splitLines->toIntegers->calculateFuel->calTotalfuel;

    totalFuel;
  };
// };

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

// Day01.getTotalFuel(file);
getTotalFuel(file)