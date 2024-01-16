static void union(int x, int y){
        int X = find(x);
        int Y = find(y);

        uf[X] = Y; 
    }

    static int find(int x){
        if(uf[x]==x){
            return x;
        }
        return uf[x] = find(uf[x]);
    }

    public static void main(String[] args) {
        // 여기에 코드를 작성해주세요.

        Scanner sc = new Scanner(System.in); 

        n = sc.nextInt(); 
        m = sc.nextInt();
        uf = new int[n+1];

        for(int i=1; i<=n; i++){
            uf[i] = i;
        }

        int countDelete = 0;

        //끊는 연산 세기 
            //합칠 때 이미 같은 그룹이면 끊어야함 
        for(int  i=0; i<m; i++){
            int x = sc.nextInt(); 
            int y = sc.nextInt();
            if(find(x)==find(y)){
                countDelete++;
                continue;
            }
            union(x, y);
        }
        //연결하는 연산 세기 
            // 그룹이 다른 것의 갯수 세기 
            // 이후 그룹 연결하기 
        int prev = find(uf[1]);
        int countPlus = 0;
        for(int i=2; i<=n; i++){
            if(find(uf[i-1])!=find(uf[i])){
                prev = find(uf[i]);
                union(i, i-1);
                countPlus++;
            }
        }
        System.out.println(countPlus+countDelete);
        
    }
}