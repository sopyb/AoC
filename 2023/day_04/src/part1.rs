use std::fs;
use std::collections::HashSet;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    let mut result = 0;

    for line in lines {
        let parts: Vec<&str> = line.split(" | ").collect();
        let winning_numbers: HashSet<i32> = parts[0].split_whitespace().filter_map(|s| s.parse().ok()).collect();
        let your_numbers: Vec<i32> = parts[1].split_whitespace().map(|s| s.parse().unwrap()).collect();

        let matches: Vec<i32> = your_numbers.into_iter().filter(|n| winning_numbers.contains(n)).collect();
        if !matches.is_empty() {
            result += 2usize.pow(matches.len() as u32 - 1);
        }
    }

    println!("{}", result);
}