class PairIE
{
public:
	int inc;
	int exc;
};
PairIE maxSum(Node* root)
{
	// bcase
	PairIE p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}
	PairIE L,R;
	L = maxSum(root->left);
	R = maxSum(root->right);
	p.inc = root->data + L.exc + R.exc;
	p.exc = max(L.inc,L.exc) + max(R.inc, R.exc);
	return p;
}