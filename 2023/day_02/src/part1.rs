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
        let game_id: i32 = parts[0][5..].parse().unwrap();
        let sets: Vec<&str> = parts[1].split("; ").collect();

        // for each set
        let mut possible = true;
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

                // check if possible
                if (*current_count > 12 && color == "red") ||
                    (*current_count > 13 && color == "green") ||
                    (*current_count > 14 && color == "blue") {
                    possible = false;
                    break;
                }
            }
        }

        // add to sum
        if possible {
            sum += game_id;
        }
    }

    // print sum
    println!("{}", sum);
}