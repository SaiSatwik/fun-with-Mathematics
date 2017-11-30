package Mathematics;

import java.util.Scanner;

public class NumberGenerator {

	/**
	 * @param args
	 */
	 public boolean isPrime(int num) {
		 if ( num < 2 ){
			 return false;
		 }
		 for (int i = 2; i <= Math.sqrt(num); i++) {
			 if ( num % i == 0 ) {
			 		return false;
			 }
		 }
		 return true;
	 }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		NumberGenerator m=new  NumberGenerator();
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		long product=1;
		int count=0;
		int[] arr=new int[n+1];
		for(int r=2,k=n;;r++){
			if(r<=k){
				if(k%r==0){
					arr[r]=arr[r]+1;
					k=k/r;
					r--;
					count++;
			    }
			}
			else{
				count--;
				break;
			}
		}
		int cnt=1;
		/*if(count>=2){
			int flag=0;
			if(arr[2]>=3){
				for(int u=3;u<=n;u++){
					if(arr[u]!=0)
						flag=1;
				}
				if(flag==0){
				int h=arr[2]/3;
				arr[2]=arr[2]-(2*h);
				arr[4]=h;
				}
			}
			if(arr[2]>3){
				int h=arr[2]/3;
				arr[2]=arr[2]-(2*h);
				arr[4]=h;
			}
		}*/
		long pro=0;
		for(int u=1;u<=n;u++){
				int q=2;
				int []ar=new int[n+1];
				product=1;
				for (int j=n;j>=2;j--){
					ar[j]=arr[j];
					while(ar[j]!=0){
							if(m.isPrime(q)){
								product=product*(long)Math.pow((long)q,(long)(j-1));
								
								q++;
								
								ar[j]--;
								cnt++;
							}
							else
								q++;
					}
				}
				if(pro==0){
					pro=product;
				}
				if(pro!=0&&pro>product){
					pro=product;
				}
				if(arr[u]>=3){
					int h=arr[u]/3;
					arr[u]=arr[u]-(2*h);
					arr[u*u]=h;
				}
		}	
		cnt--;
		System.out.print(pro);
	
	}

}
