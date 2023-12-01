fn main() {
    // read input.in
    let input = std::fs::read_to_string("src/input.in").unwrap();

    // split input into lines
    let lines = input.lines();

    let mut total = 0;

    // for each line
    for line in lines {
        let first = line.chars().find(|c| c.is_digit(10)).unwrap_or('0');
        let last = line.chars().rev().find(|c| c.is_digit(10)).unwrap_or('0');

        total += format!("{}{}", first, last).parse::<i32>().unwrap();
    }

    // print total
    println!("Total: {}", total);
}