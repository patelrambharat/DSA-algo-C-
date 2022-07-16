int kthnumber(int input1,int input2[],int input3){
    queue<int>q1,q2,q3;
    int x=1;
    for(int i=1;i<=input3;i++){
        q1.push(x*input2[0]);
        q2.push(x*input2[1]);
        q3.push(x*input2[2]);

        x= min(q1.front(),min(q2.front(),q3.front()));
        if(x == q1.front()){
            q1.pop();
        }
             if(x == q2.front()){
            q2.pop();
        }
             if(x == q3.front()){
            q3.pop();
        }
    }
    return x;
}