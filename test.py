n = 500

# グリッドを '#' で初期化
grid = [['#'] * n for _ in range(n)]

# 進行方向 (右, 下, 左, 上)
dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]

# 開始は左上コーナー、右向き
r, c, d = 0, 0, 0
grid[r][c] = '.'

while True:
    dr, dc = dirs[d]
    nr, nc = r + dr, c + dc          # 1セル先
    nr2, nc2 = r + 2*dr, c + 2*dc    # 2セル先

    # 条件を緩和：1セル先が範囲内で'#'かつ（2セル先が範囲外 OR 2セル先が'#'）
    can_move = (0 <= nr < n and 0 <= nc < n and grid[nr][nc] == '#') and (
        not (0 <= nr2 < n and 0 <= nc2 < n) or grid[nr2][nc2] == '#'
    )

    if can_move:
        r, c = nr, nc
        grid[r][c] = '.'
        continue

    # 右へ曲がる
    d = (d + 1) % 4

    # 曲がっても進めないなら終了
    dr, dc = dirs[d]
    nr, nc = r + dr, c + dc
    nr2, nc2 = r + 2*dr, c + 2*dc
    can_move = (0 <= nr < n and 0 <= nc < n and grid[nr][nc] == '#') and (
        not (0 <= nr2 < n and 0 <= nc2 < n) or grid[nr2][nc2] == '#'
    )
    if not can_move:
        break

# 行区切りで結合して文字列 s に格納
s = '\n'.join(''.join(row) for row in grid)

# デバッグ用に小さいサイズで試す場合（コメント解除）
# if __name__ == "__main__":
#     n = 21
#     print('\n'.join(''.join(row) for row in grid[:n][:n]))

with open("/home/mackerel38/competitive/out.txt", "w") as f:
    f.write(s)