struct Line{
 	ll a, b;
 	ll l = MIN, r = MAX;
 	Line(ll a, ll b): a(a), b(b) {}
 	ll operator()(ll x){
 		return a * x + b;
 	}
};

deque<Line> dq;

ll iceil(ll a, ll b){
	if(b < 0) a *= -1, b *= -1;
	if(a > 0) return (a + b - 1) / b;
	else return a / b;
}

ll intersect(Line a, Line b){
 	return iceil(a.b - b.b, b.a - a.a);
}

void add(Line ln){
 	while(!dq.empty() && ln(dq.back().l) >= dq.back()(dq.back().l)){
 		dq.pob;
	}
 	if(dq.empty()){
 		dq.eb(ln);
 		return;
 	}
	ll pos = intersect(ln, dq.back());
	if(pos > dq.back().r){
		if(dq.back().r != MAX){
			ln.l = dq.back().r + 1;
			dq.eb(ln);
	 	}
 		return;
 	}
	dq.back().r = pos - 1;
	ln.l = pos;
	dq.eb(ln);
 }

ll query(ll x){
	while(dq.front().r < x) dq.pof;
	return dq.front()(x);
}