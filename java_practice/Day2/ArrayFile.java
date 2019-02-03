
public class ArrayFile {
	public static void main(String[] args) {
		int[] a = {1, 3, 5, 6, 8};
		for (int i: a) {
			System.out.println("Array Element= " + i);
		}
		
		
		int[][] b = {{1, 2}, {3, 4, 5}, {6}};
		
		for (int[] row: b) {
			for (int i: row) {
				System.out.print(i + "\t");
			}
			System.out.println();
		}
	}
}
