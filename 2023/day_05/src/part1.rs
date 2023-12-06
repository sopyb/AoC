use std::collections::HashMap;
use std::fs;

fn main() {
    // Read the input file
    let input = fs::read_to_string("src/input.in").unwrap();
    // Split the input into seeds and maps
    let seeds_and_maps: Vec<&str> = input.split("\n\n").collect();
    // Split the first line to extract the seeds
    let seeds_and_maps_split = seeds_and_maps[0].split(": ").collect::<Vec<_>>();
    // Parse the seeds into a vector of integers
    let seeds = seeds_and_maps_split[1].split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect::<Vec<_>>();

    // Initialize the minimum location to the maximum possible value
    let mut min_location = i64::MAX;
    // Iterate over each seed
    for seed in seeds {
        // Create a dictionary to store the mapping from each stage to its value
        let mut map_dict: HashMap<String, i64> = HashMap::new();
        // Insert the seed into the dictionary
        map_dict.insert("seed".to_string(), seed);

        // Iterate over each map
        for map_string in &seeds_and_maps[1..] {
            // Split the map into lines
            let mut map_lines = map_string.split("\n").collect::<Vec<_>>();
            // Extract the from and to stages from the first line
            let map_from_to = map_lines.remove(0).split("-to-").collect::<Vec<_>>();
            let map_from = map_from_to[0].to_string();
            let map_to = map_from_to[1].trim_end_matches(" map:").to_string();

            // Iterate over each line in the map
            for map_values in map_lines {
                // Parse the values in the line
                let map_values: Vec<i64> = map_values.split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect();
                // If the current value is within the range of the map, update the value for the to stage
                if let Some(map_from_value) = map_dict.get(&map_from) {
                    if map_values[1] <= *map_from_value && *map_from_value < map_values[1] + map_values[map_values.len() - 1] {
                        map_dict.insert(map_to.clone(), map_from_value + map_values[0] - map_values[1]);
                        break;
                    }
                }
            }
            // If the to stage is not in the dictionary, copy the value from the from stage
            if !map_dict.contains_key(&map_to) {
                if let Some(map_from_value) = map_dict.get(&map_from) {
                    map_dict.insert(map_to, *map_from_value);
                }
            }
        }

        // If the location is in the dictionary, update the minimum location
        if let Some(location) = map_dict.get("location") {
            min_location = min_location.min(*location);
        }
    }

    // Print the minimum location
    println!("{}", min_location);
}