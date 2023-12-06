use std::fs;

fn main() {
    let input = fs::read_to_string("src/input.in").unwrap();
    let lines: Vec<&str> = input.lines().collect();

    // remove all non digit characters from the input first line is the time and second line is the record
    let time = lines[0].chars().filter(|c| c.is_digit(10)).collect::<String>().parse::<i64>().unwrap();
    let record = lines[1].chars().filter(|c| c.is_digit(10)).collect::<String>().parse::<i64>().unwrap();

    let mut ways = 0;

    for hold_time in 0..time {
        let speed = hold_time;
        let travel_time = time - hold_time;
        let distance = speed * travel_time;

        if distance > record {
            ways += 1;
        }
    }

    println!("{}", ways);
}