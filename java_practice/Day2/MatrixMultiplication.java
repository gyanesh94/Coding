
public class MatrixMultiplication {

	public static void main(String[] args) {
		int[][] m1 = {{1, 2, 3}, {1, 2, 3}};
		int[][] m2 = {{1, 2}, {1, 2}, {1, 2}};
		int[][] res = new int[2][2];
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				res[i][j] = 0;
				for (int k = 0; k < 3; k++) {
					res[i][j] += m1[i][k] * m2[k][j];
				}
			}
		}
		
		for (int[] row: res) {
			for (int i: row) {
				System.out.print(i + "\t");
			}
			System.out.println();
		}
	}

}
