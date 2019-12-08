module Day02 = {
  let rec getFuel = fuel =>
    if (fuel <= 0) {
      0;
    } else {
      fuel + getFuel(Day01.getTotalFuel(string_of_int(fuel)));
    };

  let rec main = input => {
    let moduleFuels =
      input->Day01.splitLines->Day01.toIntegers->Day01.calculateFuel;

    let totalFuel = Js.Array.map(getFuel, moduleFuels)->Day01.calTotalfuel;

    totalFuel;
  };
};

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Js.log(Day02.main(file));