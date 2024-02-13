# open and read the file to a string
with open("input.in", "r") as file:
    lines = file.read()
row_count = 400000

rows = [lines]
for _ in range(row_count - 1):
    previous_row = '.' + rows[-1] + '.'
    next_row = ''
    for i in range(1, len(previous_row) - 1):
        pattern = previous_row[i-1:i+2]
        if pattern in ['^^.', '.^^', '^..', '..^']:
            next_row += '^'
        else:
            next_row += '.'
    rows.append(next_row)

safe_tiles = sum(row.count('.') for row in rows)

print(safe_tiles)
