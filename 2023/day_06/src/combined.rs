use std::fs;

fn calculate_ways(time: i64, record: i64, is_part1: bool) -> i64 {
    let mut ways = 0;

    for hold_time in 0..time {
        let speed = hold_time;
        let travel_time = time - hold_time;
        let distance = if is_part1 { (time - hold_time) * hold_time } else { speed * travel_time };

        if distance > record {
            ways += 1;
        }
    }

    ways
}

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    // Part 1
    let times = lines[0].split_whitespace()
        .skip(1)
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<i64>>();
    let records = lines[1].split_whitespace()
        .skip(1)
        .map(|s| s.parse::<i64>().unwrap())
        .collect::<Vec<i64>>();

    let races: Vec<(i64, i64)> = times.into_iter().zip(records.into_iter()).collect();

    let mut total_ways = 1;

    for (time, record) in races {
        total_ways *= calculate_ways(time, record, true);
    }

    println!("Total ways for part 1: {}", total_ways);

    // Part 2
    let time = lines[0].chars().filter(|c| c.is_digit(10)).collect::<String>().parse::<i64>().unwrap();
    let record = lines[1].chars().filter(|c| c.is_digit(10)).collect::<String>().parse::<i64>().unwrap();

    let ways = calculate_ways(time, record, false);

    println!("Ways for part 2: {}", ways);
}