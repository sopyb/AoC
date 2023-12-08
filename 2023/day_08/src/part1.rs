use std::collections::HashMap;
use std::fs;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();
    let steps: Vec<char> = lines[0].chars().collect();
    let mut routes = HashMap::new();

    for line in &lines[2..] {
        let tokens: Vec<&str> = line.split_whitespace().collect();
        let start = tokens[0].to_string();
        let l = tokens[2].trim_start_matches('(').trim_end_matches(',').to_string();
        let r = tokens[3].trim_end_matches(')').to_string();
        routes.insert(start, (l, r));
    }

    let mut curr = "AAA".to_string();
    let mut i = 0;

    loop {
        let next = steps[i % steps.len()];
        curr = if next == 'L' {
            routes[&curr].0.clone()
        } else {
            routes[&curr].1.clone()
        };
        i += 1;
        if curr == "ZZZ" {
            break;
        }
    }

    println!("{}", i);
}