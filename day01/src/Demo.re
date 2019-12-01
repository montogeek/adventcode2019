let splitLines = lines => Js.String.split("\n", lines);
let toIntegers = strings => Js.Array.map(int_of_string, strings);
let calculateFuel = masses =>
  Js.Array.map(mass => Js.Math.floor(Js.Int.toFloat(mass / 3)) - 2, masses);
let calculateTotalFuel = fuels => Js.Array.reduce((a, b) => a + b, 0, fuels);

let main = () => {
  let file = Node.Fs.readFileAsUtf8Sync("./input.txt");
  let totalFuel =
    file->splitLines->toIntegers->calculateFuel->calculateTotalFuel;
  totalFuel;
};

main();