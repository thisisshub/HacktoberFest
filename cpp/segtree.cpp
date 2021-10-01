struct node
{
    int s, e, m; // start end and middle of the range represented by current node
    int val; // value in current node
    node *l, *r; // pointers to left and right children
    // Build the tree
    node(int S, int E, vi arr)
    {
		s = S, e = E, m = (s+e)/2;
		if(s != e) // if not leaf create children
        {
			l = new node(s, m, arr); // create left child
			r = new node(m+1, e, arr); // create right child
            // find value of current range from children
            // val = some function of (l->val, r->val)
		}
        if(s==e) val = arr[s]; // if leaf no children
	}
    // query the tree
    int query(int qS, int qE) // (qS,qE) is the queried range
    {
		if((s>qE)||(e<qS)) return 0; // no overlap
        if((s>=qS)&&(e<=qE)) return val; // complete overlap
        // else for partial overlap, query children
        // return (some function of ( l->query(qS,qE), r->query(qS,qE) ) ); 
	}
    // update the tree
    void update(int qIndx, int qVal)
    {
        if(s==e) // if target leaf node reached, update it
        {
            val = qVal;
            return;
        }
        // update only the child which contains target
        if(qIndx>m) r->update(qIndx, qVal);
        else l->update(qIndx,qVal);
        // update val of current node
        // val = some function of (l->val, r->val) ;
    }
} *root;