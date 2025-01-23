class Solution{
public:		
    char get_char(char centre, int rem, int half){
        if(half == 0) return centre;
        if(rem <= half) return get_char(centre == '0' ? '0' : '1', rem, half/2);
        return get_char(centre == '0' ? '1' : '0', rem - half, half/2);
    }
    
	char kthCharacter(int m, int n, int k){
	    string binary_string;
	    if(m == 0) binary_string = "0";
	    else binary_string = bitset <32> (m).to_string().substr(32-((int)log2(m) + 1));
	    
	    if(n == 0) return binary_string[k-1];
	    
	    int extension = (1 << n);
	    int f = k/extension;
	    int r = k % extension;
	    
	    if(r == 0){
	        if(binary_string[f-1] == '0' && n%2 == 1) return '1';
	        if(binary_string[f-1] == '1' && n%2 == 0) return '1';
	        return '0';
	    }else{
	        return get_char(binary_string[f], r, extension/2);
	    }

	}
};
