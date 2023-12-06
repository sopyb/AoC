use std::collections::HashMap;
use std::collections::VecDeque;
use std::fs;

fn main() {
    // Read the input file
    let input = fs::read_to_string("src/input.in").unwrap();
    // Split the input into seeds and maps
    let seeds_and_maps = input.split("\n\n").collect::<Vec<_>>();
    // Split the first line to extract the seeds
    let seeds_and_maps_split = seeds_and_maps[0].split(": ").collect::<Vec<_>>();
    // Parse the seeds into a vector of integers
    let seeds = seeds_and_maps_split[1].split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect::<Vec<_>>();

    // Initialize the minimum location to the maximum possible value
    let mut min_location = i64::MAX;
    // Iterate over each pair of seeds
    for i in (0..seeds.len()).step_by(2) {
        // Create a dictionary to store the mapping from each stage to its range
        let mut map_dict: HashMap<String, VecDeque<(i64, i64)>> = HashMap::new();
        // Insert the seed range into the dictionary
        map_dict.entry("seed".to_string()).or_insert(VecDeque::new()).push_back((seeds[i], seeds[i] + seeds[i + 1]));

        // Iterate over each map
        for map_string in &seeds_and_maps[1..] {
            // Split the map into lines
            let map_lines = map_string.split("\n").collect::<Vec<_>>();
            // Extract the from and to stages from the first line
            let map_from_to = map_lines[0].split("-to-").collect::<Vec<_>>();
            let map_from = map_from_to[0];
            let map_to = map_from_to[1].trim_end_matches(" map:");

            // Get the current map from the dictionary
            let current_map_option = map_dict.get(map_from);
            if let Some(current_map_value) = current_map_option {
                let mut current_map = current_map_value.clone();
                // Iterate over each range in the current map
                while let Some(current_range) = current_map.pop_front() {
                    // Iterate over each line in the map
                    for map_values in &map_lines[1..] {
                        // Parse the values in the line
                        let map_values = map_values.split_whitespace().map(|x| x.parse::<i64>().unwrap()).collect::<Vec<_>>();
                        let mut new_range = current_range.clone();
                        // If the current range overlaps with the map range, update the range
                        if map_values[1] < current_range.1 && map_values[1] + map_values[map_values.len() - 1] > current_range.0 {
                            if map_values[1] <= current_range.0 {
                                new_range.0 = current_range.0 + map_values[0] - map_values[1];
                            } else {
                                new_range.0 = map_values[0];
                            }
                            if current_range.1 <= map_values[1] + map_values[map_values.len() - 1] {
                                new_range.1 = current_range.1 + map_values[0] - map_values[1];
                            } else {
                                new_range.1 = map_values[0] + map_values[map_values.len() - 1];
                            }
                            // If the new range is different from the current range, update the dictionary
                            if new_range != current_range {
                                if new_range.0 != current_range.0 + map_values[0] - map_values[1] {
                                    current_map.push_back((current_range.0, map_values[1]));
                                }
                                if new_range.1 != current_range.1 + map_values[0] - map_values[1] {
                                    current_map.push_back((map_values[1] + map_values[map_values.len() - 1], current_range.1));
                                }
                                map_dict.entry(map_to.to_string()).or_insert(VecDeque::new()).push_back(new_range);
                                break;
                            } else {
                                map_dict.entry(map_to.to_string()).or_insert(VecDeque::new()).push_back(current_range);
                            }
                        }
                    }
                }
                // Sort the location ranges and update the minimum location
                map_dict.entry("location".to_string()).or_insert(VecDeque::new()).make_contiguous().sort_by_key(|g| g.0);
                if let Some(first_location) = map_dict.get("location").and_then(|v| v.front()) {
                    min_location = min_location.min(first_location.0);
                }
            }
        }
    }

    // Print the minimum location
    println!("{}", min_location);
}