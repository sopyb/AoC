use std::collections::HashMap;

fn main() {
    // read input.in
    let input = std::fs::read_to_string("src/input.in").unwrap();

    // split input into lines
    let lines = input.lines();

    // for each line
    let mut sum = 0;
    for line in lines {
        // split line into parts (game id and sets)
        let parts: Vec<&str> = line.split(": ").collect();
        // ? game id removed so rustc doesn't give a warning
        let sets: Vec<&str> = parts[1].split("; ").collect();

        // for each set
        let mut min_cubes = HashMap::new();
        for set in sets {
            // for each cube
            let mut cubes = HashMap::new();
            for cube in set.split(", ") {
                // split cube into parts (count and color)
                let cube_parts: Vec<&str> = cube.split(" ").collect();
                let count: i32 = cube_parts[0].parse().unwrap();
                let color = cube_parts[1];

                // add count to cubes map
                let current_count = cubes.entry(color).or_insert(0);
                *current_count += count;

                // add count to min_cubes map
                let min_count = min_cubes.entry(color).or_insert(0);
                *min_count = (*min_count).max(*current_count);
            }
        }

        // calculate power
        let power = min_cubes.values().product::<i32>();
        sum += power;
    }

    // print sum
    println!("{}", sum);
}