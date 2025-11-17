import java.io.*;		
class test1{				
	public static void main(String args[]){
		int ch,n1,n2,res=0;
		n1 = Integer.parseInt(args[0]);
		n2 = Integer.parseInt(args[1]);	
		ch = Integer.parseInt(args[2]);
		switch(ch){
			case 1:
				res = n1+n2;
				break;
			case 2:
				res = n1-n2;
				break;
			case 3:
				res = n1*n2;
				break;
			case 4:
				if(n2 == 0){
					break;
				}
				res = n1/n2;
				break;
		}
		System.out.println("result:" + res);	
	}			
}	