class Solution {
  public:
    vector <int> bottomView(Node *root) {
        //Your code here
        vector<int>ans; //this is used to store ans
        if(root == NULL)
            return ans;
        
        map<int,int>topNode;  //this is used for one - one mapping 
        
        queue<pair<Node* , int>>q;
        q.push(make_pair(root,0));
        while(!q.empty()){
            
            pair<Node* , int> temp = q.front();
            //tu nikall
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
           
                topNode[hd] = frontNode-> data;     //isme and top view me thoda yhi bs different hai isme yha top view wala condition check nhi hoga
            if(frontNode -> left)
                q.push(make_pair(frontNode -> left,hd -1));
            
            if(frontNode -> right )
                q.push(make_pair(frontNode -> right, hd+1));
        }
        for(auto i: topNode){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }

};
