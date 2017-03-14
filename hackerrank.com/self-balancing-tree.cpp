/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

int bf(node* r) {
    if (!r) return 0;
    return (r->left ? r->left->ht : -1) -
            (r->right ? r->right->ht : -1);
}

int hf(node* root) {
    return 1 + 
       max(
        (root->right ? root->right->ht : -1), 
        (root->left  ? root->left->ht  : -1));
}

node* insert(node* root, int val) {
   if (!root) {
       root = new node();
       root->val = val;
       root->ht = 0;
      
       return root;
   }
    
    //
    // Insertion Phase
    //
    
   if (root->val <= val) {
       // insert into right sub-tree
       if (root->right) {
           root->right = insert(root->right, val);
       } else {
           node* n = new node();
           n->val = val;
           n->ht = 0;
           root->right = n;
       }
   } else {
       // insert into left sub-tree
       if (root->left) {
           root->left = insert(root->left, val);
       } else {
           node* n = new node();
           n->val = val;
           n->ht = 0;
           root->left = n;
       }
   }
    
    // set height
    root->ht = hf(root);
       
    //
    // Balance Phase
    //
    
    
    // check balance factor
    int f = bf(root);
    
    if (f > 1) {
        int lf = bf(root->left);
        if (lf < 0) {
            // Left Right Case
            node* lc = root->left;
            node* lrc = lc->right;
            lc->right = lrc->left;
            lrc->left = lc;
            root->left = lrc;
            
            lc->ht = hf(lc);
            lrc->ht = hf(lrc);
        }
        
        // Left Left Case
        node* lc = root->left;
        root->left = lc->right;
        lc->right = root;
        
        lc->right->ht = hf(lc->right);
        lc->ht = hf(lc);
        
        return lc;
        
    } else if (f < -1) {
        int rf = bf(root->right);
        if (rf > 0) {
            // Right Left Case
            node* rc = root->right;
            node* rlc = rc->left;
            rc->left = rlc->right;
            rlc->right = rc;
            root->right = rlc;
            
            rc->ht = hf(rc);
            rlc->ht = hf(rlc);
        }
        
        // Right Right Case
        node* rc = root->right;
        root->right = rc->left;
        rc->left = root;
        
        rc->left->ht = hf(rc->left);
        rc->ht = hf(rc);
        
        return rc;
    }

    
    
    return root;
}
