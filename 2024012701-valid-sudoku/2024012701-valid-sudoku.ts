/*
 * 36. Valid Sudoku
 * https://leetcode.com/problems/valid-sudoku/description/
*/

const isValidSudoku = (board: string[][]): boolean => {
  for (let i = 0; i < board.length; i++) {
    const valuesSetX = new Set();
    const valuesSetY = new Set();

    for (let j = 0; j < board[i].length; j++) {
      if (board[i][j] === '.') continue;

      if (valuesSetX.has(board[i][j])) {
        return false;
      }

      valuesSetX.add(board[i][j]);
    }

    for (let j = 0; j < board[i].length; j++) {
      if (board[j][i] === '.') continue;

      if (valuesSetY.has(board[j][i])) {
        return false;
      }

      valuesSetY.add(board[j][i]);
    }
  }

  for (let i = 0; i < board.length; i += 3) {
    for (let j = 0; j < board.length; j += 3) {

      const valuesSetSubBox = new Set();

      for (let k = 0; k < board[i].length; k++) {
        let y = i + Math.floor(k / 3);
        let x = j + k % 3;

        if (board[y][x] === '.') continue;

        if (valuesSetSubBox.has(board[y][x])) {
          return false;
        }

        valuesSetSubBox.add(board[y][x]);
      }
    }
  }

  return true;
};