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

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Js.log(Part2.main(file));