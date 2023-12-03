use std::fs;

fn main() {
    // read input.in
    let input = fs::read_to_string("src/input.in").unwrap();

    // convert input to grid
    let grid: Vec<Vec<char>> = input.lines().map(|line| line.chars().collect()).collect();
    let grid_height = grid.len();
    let grid_width = grid[0].len();

    // define helper functions
    let is_symbol = |c: char| !c.is_digit(10) && c != '.';
    let is_valid_coordinate = |row: isize, col: isize| 0 <= row && row < grid_height as isize && 0 <= col && col < grid_width as isize;

    // for every line
    let mut sum = 0;
    for row in 0..grid_height {
        // for every character
        let mut col = 0;
        while col < grid_width {
            // if character is a digit
            if grid[row][col].is_digit(10) {
                let mut number = 0;
                let start_col = col;
                
                // read whole number
                while col < grid_width && grid[row][col].is_digit(10) {
                    number = number * 10 + (grid[row][col] as u8 - b'0') as i32;
                    col += 1;
                }
                let end_col = col - 1;

                // check if adjacent to symbol
                let mut is_adjacent_to_symbol = false;
                for k in (start_col as isize - 1)..=(end_col as isize + 1) {
                    for ii in (row as isize - 1)..=(row as isize + 1) {
                        if is_valid_coordinate(ii, k) && is_symbol(grid[ii as usize][k as usize]) {
                            is_adjacent_to_symbol = true;
                            break;
                        }
                    }
                    if is_adjacent_to_symbol {
                        break;
                    }
                }
                
                // if adjacent to symbol, add to sum
                if is_adjacent_to_symbol {
                    sum += number;
                }
            } else {
                col += 1;
            }
        }
    }

    // print sum
    println!("{}", sum);
}