use std::fs;
use std::collections::HashSet;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect::<Vec<_>>();

    let mut result1 = 0;
    let mut result2 = 0;
    let mut multiplier: Vec<i32> = vec![1; lines.len()];

    for (i, line) in lines.iter().enumerate() {
        let parts: Vec<&str> = line.split(":").collect();
        let winning_numbers: HashSet<i32> = parts[1].split("|").next().unwrap().trim().split_whitespace().map(|s| s.parse().unwrap()).collect();
        let your_numbers: Vec<i32> = parts[1].split("|").nth(1).unwrap().trim().split_whitespace().map(|s| s.parse().unwrap()).collect();

        let matches: Vec<i32> = your_numbers.into_iter().filter(|n| winning_numbers.contains(n)).collect();

        if !matches.is_empty() {
            result1 += 2i32.pow((matches.len() - 1) as u32);
        }

        let current_multiplier = multiplier[i];

        for j in (i+1)..std::cmp::min(i + matches.len() + 1, lines.len()) {
            multiplier[j] += current_multiplier;
        }

        result2 += current_multiplier;
    }

    println!("{}\n{}", result1, result2);
}