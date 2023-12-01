fn main() {
    let input = std::fs::read_to_string("src/input.in").unwrap();

    let lines = input.lines();

    // ! I lost over a bricking hour debugging this :(( Forgot Overlapping numbers might be a thing
    let digit_mapping = [
        ("one", "one1one"),
        ("two", "two2two"),
        ("three", "three3three"),
        ("four", "four4four"),
        ("five", "five5five"),
        ("six", "six6six"),
        ("seven", "seven7seven"),
        ("eight", "eight8eight"),
        ("nine", "nine9nine"),
    ];

    let mut total = 0;

    for line in lines {
        // println!("Line: {}", line);
        let mut line_with_digits = line.to_string();

        for (digit, replacement) in digit_mapping.iter() {
            line_with_digits = line_with_digits.replace(digit, replacement);
        }
        // println!("Line with digits: {}", line_with_digits);

        let first = line_with_digits.chars().find(|c| c.is_digit(10)).unwrap_or('0');
        let last = line_with_digits.chars().rev().find(|c| c.is_digit(10)).unwrap_or('0');

        let combined = format!("{}{}", first, last).parse::<i32>().unwrap();
        // println!("Combined: {}", combined);
        // println!("\n");

        total += combined;
    }

    println!("Total: {}", total);
}