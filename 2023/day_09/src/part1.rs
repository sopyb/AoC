use std::collections::HashSet;
use std::fs;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    let mut total_sum = 0;

    for line in lines {
        let mut numbers: Vec<i32> = line.split_whitespace()
            .map(|s| s.parse().unwrap())
            .collect();
        let mut number_grid = vec![numbers.clone()];
        while number_grid.last().unwrap().iter().collect::<HashSet<_>>().len() > 1 {
            let next_line: Vec<i32> = number_grid.last().unwrap().windows(2)
                .map(|window| window[1] - window[0])
                .collect();
            number_grid.push(next_line);
        }
        let mut sum = *number_grid.last().unwrap().first().unwrap();
        for i in (0..number_grid.len() - 1).rev() {
            sum += *number_grid[i].last().unwrap();
        }
        total_sum += sum;
    }

    println!("{}", total_sum);
}