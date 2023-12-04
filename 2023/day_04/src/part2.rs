use std::fs;
use std::collections::HashSet;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    let mut result = 0;
    let mut multipliers: Vec<usize> = vec![1; lines.len()];

    for i in 0..lines.len() {
        let scratchcard_line = lines[i];
        let parts: Vec<&str> = scratchcard_line.split(" | ").collect();
        let winning_numbers: HashSet<i32> = parts[0].split_whitespace().filter_map(|s| s.parse().ok()).collect();
        let player_numbers: Vec<i32> = parts[1].split_whitespace().map(|s| s.parse().unwrap()).collect();

        let matching_numbers: Vec<i32> = player_numbers.into_iter().filter(|n| winning_numbers.contains(n)).collect();
        let current_multiplier = multipliers[i];

        for j in (i+1)..std::cmp::min(i + matching_numbers.len() + 1, lines.len()) {
            multipliers[j] += current_multiplier;
        }

        result += current_multiplier;
    }

    println!("{}", result);
}