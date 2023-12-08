use std::collections::HashMap;
use std::fs;
use num::Integer;

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

    let mut poses = vec![];
    for k in routes.keys() {
        if k.ends_with("A") {
            poses.push(k.clone());
        }
    }

    let mut cycles = vec![];
    for pos in poses {
        let mut curr = pos;
        let mut i = 0;
        loop {
            let next = steps[i % steps.len()];
            curr = if next == 'L' {
                routes[&curr].0.clone()
            } else {
                routes[&curr].1.clone()
            };
            i += 1;
            if curr.ends_with("Z") {
                break;
            }
        }
        cycles.push(i);
    }

    println!("{}", cycles.iter().fold(1, |a, b| a.lcm(b)));
}