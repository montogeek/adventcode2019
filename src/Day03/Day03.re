module ManhattanDistance = {
  let main = (a, b) => {
    let distance = ref(0);
    let dimensions =
      Js.Math.max_int(Js.Array.length(a), Js.Array.length(b));
    for (i in 0 to dimensions) {
      let aValue =
        switch (a[i]) {
        | x => x
        | exception (Invalid_argument("index out of bounds")) => 0
        };

      let bValue =
        switch (b[i]) {
        | x => x
        | exception (Invalid_argument("index out of bounds")) => 0
        };

      distance := distance^ + Js.Math.abs_int(bValue - aValue);
    };

    distance;
  };
};

module Day03 = {
  module Part1 = {
    let getBounds = ()

    let main = input => {
      let values = Js.String.split("\n", input);
      Js.log(values);
    };
  };
};

let file = Node.Fs.readFileAsUtf8Sync("./input.txt");

Day03.Part1.main(
  "R75,D30,R83,U83,L12,D49,R71,U7,L72\nU62,R66,U55,R34,D71,R55,D58,R83",
)
->Js.log;