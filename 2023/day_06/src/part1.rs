use std::fs;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    let times = lines[0].split_whitespace()
        .skip(1)
        .map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();
    let records = lines[1].split_whitespace()
        .skip(1)
        .map(|s| s.parse::<i32>().unwrap())
        .collect::<Vec<i32>>();

    let races: Vec<(i32, i32)> = times.into_iter().zip(records.into_iter()).collect();

    let mut total_ways = 1;

    for (time, record) in races {
        let mut ways_to_win = 0;

        for hold_time in 0..time {
            let distance = (time - hold_time) * hold_time;

            if distance > record {
                ways_to_win += 1;
            }
        }

        total_ways *= ways_to_win;
    }

    println!("{}", total_ways);
}