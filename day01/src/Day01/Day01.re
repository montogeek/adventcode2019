module Day01 = {
  module Part1 = {
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
      let totalFuel =
        input->splitLines->toIntegers->calculateFuel->calTotalfuel;

      totalFuel;
    };
  };

  module Part2 = {
    let rec getFuel = fuel =>
      if (fuel <= 0) {
        0;
      } else {
        fuel + getFuel(Part1.getTotalFuel(string_of_int(fuel)));
      };

    let rec main = input => {
      let moduleFuels =
        input->Part1.splitLines->Part1.toIntegers->Part1.calculateFuel;

      let totalFuel = Js.Array.map(getFuel, moduleFuels)->Part1.calTotalfuel;

      totalFuel;
    };
  };
};

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Day01.Part1.getTotalFuel(file);
Day01.Part2.main(file);