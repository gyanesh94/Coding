
public class LabelBreakContinue {

	@SuppressWarnings("unused")
	public static void main(String[] args) {
		
		boolean val = true;
		labelA: {
			System.out.println("Printing labelA");
			
			labelB: {
				System.out.println("Printing before labelB");
				
				labelC: {
					System.out.println("Printing in labelC");
					if (val)
						break labelB;
					System.out.println("Printing in labelC2");
				}
				System.out.println("Printing in labelB2");
			}
			System.out.println("Printing in labelA2");
		}
		
		
		loopA: for(int i = 0; i <= 3; i++) {
			loopB: for (int j = 1; j <= 3; j++) {
				System.out.println("Before print i:" + i + " j:" + j);
				if (i == j) continue loopA;
				System.out.println("After print i:" + i + " j:" + j);
			}
			System.out.println("in loopA");
		}
	}

}
