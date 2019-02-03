package Day7;

import java.util.Scanner;

public class LaughingBomb {

	private static int n;
	private static int m;
	private static int[][] map;
	private static int a;
	private static int b;
	private static int[][] cost;
	private static int[] ans;
	private static int index;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int testCase = sc.nextInt();
		ans = new int[testCase];
		index = 0;
		while (testCase > 0) {
			m = sc.nextInt();
			n = sc.nextInt();

			map = new int[n + 1][m + 1];
			cost = new int[n + 1][m + 1];

			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					map[i][j] = sc.nextInt();
					cost[i][j] = Integer.MAX_VALUE;
				}
			}

			b = sc.nextInt();
			a = sc.nextInt();
			
			bfs(a, b);
			
			testCase--;
		}
		sc.close();
		
		for (int i : ans) {
			System.out.println(i);
		}
	}

	private static void bfs(int a, int b) {
		Node[] Q = new Node[n * m + 1];
		Node nNode = new Node(a, b);
		cost[a][b] = 1;
		int rear = -1;
		int front = 0;
		Q[++rear] = nNode;
		
		int max = -1;
		
		while (rear >= front) {
			Node ref = Q[front++];

			if (ref.x - 1 > 0 && cost[ref.x - 1][ref.y] > cost[ref.x][ref.y] + 1 && map[ref.x - 1][ref.y] == 1) {
				cost[ref.x - 1][ref.y] = cost[ref.x][ref.y] + 1;
				Q[++rear] = new Node(ref.x - 1, ref.y);
				
				if (max < cost[ref.x - 1][ref.y]) {
					max = cost[ref.x - 1][ref.y];
				}
			}
			
			if (ref.x + 1 <= n && cost[ref.x + 1][ref.y] > cost[ref.x][ref.y] + 1 && map[ref.x + 1][ref.y] == 1) {
				cost[ref.x + 1][ref.y] = cost[ref.x][ref.y] + 1;
				Q[++rear] = new Node(ref.x + 1, ref.y);
				
				if (max < cost[ref.x + 1][ref.y]) {
					max = cost[ref.x + 1][ref.y];
				}
			}
			
			if (ref.y - 1 > 0 && cost[ref.x][ref.y - 1] > cost[ref.x][ref.y] + 1 && map[ref.x][ref.y - 1] == 1) {
				cost[ref.x][ref.y - 1] = cost[ref.x][ref.y] + 1;
				Q[++rear] = new Node(ref.x, ref.y - 1);
				
				if (max < cost[ref.x][ref.y - 1]) {
					max = cost[ref.x][ref.y - 1];
				}
			}
			
			if (ref.y + 1 <= m && cost[ref.x][ref.y + 1] > cost[ref.x][ref.y] + 1 && map[ref.x][ref.y + 1] == 1) {
				cost[ref.x][ref.y + 1] = cost[ref.x][ref.y] + 1;
				Q[++rear] = new Node(ref.x, ref.y + 1);
				
				if (max < cost[ref.x][ref.y + 1]) {
					max = cost[ref.x][ref.y + 1];
				}
			}

		}
		
		ans[index++] = max;
		
//		System.out.println();
//		
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				System.out.print(cost[i][j] + "\t");
//			}
//			System.out.println();
//		}
//		System.out.println("Max " + max);
	}

	static class Node {
		int x;
		int y;

		public Node(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}

}
