//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<algorithm>
//#include<set>
//using namespace std;
//
//
//
//class MuchieCost {
//
//private:
//	int nod_init;
//	int nod_final;
//	int cost;
//
//public:
//
//	MuchieCost(int n1, int n2, int c) :nod_init{ n1 }, nod_final{ n2 }, cost{ c }{}
//
//	int get_nod_init() { return nod_init; }
//	int get_nod_final() { return nod_final; }
//	int get_cost() { return cost; }
//
//	void set_nod_init(int n1) { nod_init = n1; }
//	void set_nod_final(int n2) { nod_final = n2; }
//	void set_cost(int c) { cost = c; }
//};
//
//bool compare(MuchieCost m1, MuchieCost m2) { return (m1.get_cost() < m2.get_cost()); }
//
//class Graf
//{
//
//private:
//
//	int nr_noduri;
//	int nr_muchii;
//	int start;
//	vector<vector<int>> lista;
//	vector<MuchieCost>muchiiCost;
//
//public:
//
//	int get_nr_noduri() { return nr_noduri; }
//	//void set_nr_noduri(int n) { nr_noduri = n; }
//
//	int get_nr_muchii() { return nr_muchii; }
//	//void set_nr_muchii(int m) { nr_muchii = m; }
//
//	int get_start() { return start; }
//	//void set_start(int s) { start = s; }
//
//	Graf() {}
//
//	//dfs
//	void citire_graf_dfs() {
//
//		ifstream f("dfs.in");
//		int x, y;
//		f >> nr_noduri;
//		f >> nr_muchii;
//
//		lista.resize(get_nr_noduri() + 1);
//
//
//		while (f >> x >> y) {
//
//			lista[x].push_back(y);
//			lista[y].push_back(x);
//
//		}
//
//		f.close();
//	}
//	void dfs(int start, vector<int>& vizit) {
//
//		int v;
//		stack<int>st;
//		int x;
//
//		st.push(start);
//		vizit[start] = 1;
//
//		while (!st.empty()) {
//
//			x = st.top();
//			v = 0;
//
//
//			for (int i = 0; i < lista[x].size(); i++) {
//
//
//				if (vizit[lista[x][i]] == 0) {
//
//					v = lista[x][i];
//					break;
//				}
//			}
//
//
//			if (v == 0) { st.pop(); }
//			else {
//
//				st.push(v);
//				vizit[v] = 1;
//			}
//		}
//	}
//	void comp_conexe() {
//
//		citire_graf_dfs();
//
//		vector<int> vizit;
//		for (int i = 0; i <= nr_noduri; i++) { vizit.push_back(0); }
//
//		int count = 0;
//
//		for (int i = 1; i <= nr_noduri; i++) {
//
//			if (vizit[i] == 0) {
//
//				dfs(i, vizit);
//				count++;
//			}
//
//		}
//
//		ofstream g("dfs.out");
//		g << count;
//		g.close();
//	}
//
//
//
//	//bfs
//	void citire_graf_bfs() {
//
//		ifstream f("bfs.in");
//		int x, y;
//		f >> nr_noduri;
//		f >> nr_muchii;
//		f >> start;
//
//		lista.resize(get_nr_noduri() + 1);
//
//		while (f >> x >> y) {
//
//			lista[x].push_back(y);
//		}
//	}
//	void bfs() {
//
//		citire_graf_bfs();
//
//		queue<int>coada;
//		int x;
//
//		vector<int> vizit;
//		for (int i = 0; i <= nr_noduri; i++) { vizit.push_back(-1); }
//
//		coada.push(start);
//		vizit[start] = 0;
//
//		while (!coada.empty()) {
//
//			x = coada.front();
//			coada.pop();
//
//			for (int i = 0; i < lista[x].size(); i++) {
//
//				if (vizit[lista[x][i]] == -1) {
//
//					coada.push(lista[x][i]);
//					vizit[lista[x][i]] = vizit[x] + 1;
//				}
//			}
//		}
//
//		ofstream g("bfs.out");
//		for (int i = 1; i <= nr_noduri; i++) {
//
//			g << vizit[i] << " ";
//		}
//		g.close();
//	}
//
//
//	//sortare topologica
//	void citire_ST() {
//
//		ifstream f("sortaret.in");
//		int x, y;
//		f >> nr_noduri;
//		f >> nr_muchii;
//
//
//		lista.resize(get_nr_noduri() + 1);
//
//
//		while (f >> x >> y) {
//
//			lista[x].push_back(y);
//
//		}
//		f.close();
//	}
//	void dfs_topologic(int start, vector<int>& vizit, vector<int>& topo) {
//
//		int v;
//		stack<int>st;
//		int x;
//
//		st.push(start);
//		vizit[start] = 1;
//
//		while (!st.empty()) {
//
//			x = st.top();
//			v = 0;
//
//
//			for (int i = 0; i < lista[x].size(); i++) {
//
//
//				if (vizit[lista[x][i]] == 0) {
//
//					v = lista[x][i];
//					break;
//				}
//			}
//
//
//			if (v == 0) { topo.push_back(st.top()); st.pop(); }
//			else {
//
//				st.push(v);
//				vizit[v] = 1;
//			}
//		}
//	}
//	void SortareTopologica() {
//
//		citire_ST();
//
//		vector<int> topo;
//		vector<int> vizit;
//
//		for (int i = 0; i <= nr_noduri; i++) { vizit.push_back(0); }
//
//		for (int i = 1; i <= nr_noduri; i++) {
//
//			if (vizit[i] == 0) {
//
//				dfs_topologic(i, vizit, topo);
//
//			}
//
//		}
//
//		ofstream g("sortaret.out");
//		for (int i = topo.size() - 1; i >= 0; i--) {
//
//			g << topo[i] << " ";
//		}
//		g.close();
//	}
//
//	//havel hakimi
//	void HavelHakimi() {
//
//		ifstream f("havel.in");
//		int x;
//		vector<int> v;
//
//		while (f >> x) {
//
//			v.push_back(x);
//		}
//
//		int ok = 0;
//		int fst;
//
//		while (ok == 0) {
//
//			sort(v.begin(), v.end(), greater<>());
//
//			if (v[0] == 0) { ok = 1; break; }
//
//			fst = v[0];
//			v.erase(v.begin() + 0);
//
//			if (fst > v.size()) { break; }
//
//			for (int i = 0; i < v.size(); i++) {
//
//				v[i]--;
//				if (v[i] < 0) { break; }
//			}
//
//		}
//
//
//		ofstream g("havel.out");
//		if (ok == 0) {
//
//			g << "NU";
//		}
//		else { g << "DA"; }
//
//		g.close();
//	}
//
//	//muchie critica
//	void citire_muchie_critica(int& m, vector<vector<int>>& connections) {
//
//		int x, y;
//		cin >> m;
//
//		connections.resize(m + 1);
//
//		for (int i = 0; i < m; i++) {
//
//			cin >> x >> y;
//
//			connections.push_back({ x,y });
//		}
//	}
//	void muchie_critica(int& n, vector<vector<int>>& connections) {
//
//		int m;
//		cin >> n;
//		cin >> m;
//
//		citire_muchie_critica(m, connections);
//
//	}
//	void df(int i, vector<int>& vizit, vector<int>& nivel, vector<int>& nivel_min, vector<vector<int>> lista, vector<vector<int>>& muchii) {
//
//
//		vizit[i] = 1;
//		nivel_min[i] = nivel[i];
//
//		for (int j = 0; j < lista[i].size(); j++) {
//
//			if (vizit[lista[i][j]] == 0) {
//
//				nivel[lista[i][j]] = nivel[i] + 1;
//
//				df(lista[i][j], vizit, nivel, nivel_min, lista, muchii);
//
//				nivel_min[i] = min(nivel_min[i], nivel_min[lista[i][j]]);
//
//				if (nivel_min[lista[i][j]] > nivel[i]) { muchii.push_back({ i, lista[i][j] }); }
//
//			}
//			else {
//
//				if (nivel[lista[i][j]] < nivel[i] - 1) { nivel_min[i] = min(nivel_min[i], nivel[lista[i][j]]); }
//			}
//
//		}
//
//
//	}
//	vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
//
//		//vector<vector<int>> connections;
//		muchie_critica(n, connections);
//
//		vector<vector<int>>lista, muchii;
//		lista.resize(n + 1);
//
//		for (int i = 0; i < connections.size(); i++) {
//
//			lista[connections[i][0]].push_back(connections[i][1]);
//			lista[connections[i][1]].push_back(connections[i][0]);
//		}
//
//
//		vector<int>vizit, nivel_min, nivel;
//
//		for (int i = 0; i <= n; i++) { vizit.push_back(0); nivel.push_back(0); nivel_min.push_back(0); }
//
//
//		df(0, vizit, nivel, nivel_min, lista, muchii);
//
//		return muchii;
//
//	}
//
//
//	//apm- kruskal
//
//	void citire_apm() {
//
//		ifstream f("apm.in");
//		int n1, n2, c;
//		f >> nr_noduri;
//		f >> nr_muchii;
//
//		while (f >> n1 >> n2 >> c) {
//
//			muchiiCost.push_back(MuchieCost(n1, n2, c));
//		}
//		f.close();
//	}
//	int reprez(int u, vector<int>& tata) {
//
//		while (tata[u] != 0) { u = tata[u]; }
//		return u;
//	}
//	void reuneste(int u, int v, vector<int>& tata, vector<int>& h) {
//
//		int ru, rv;
//		ru = reprez(u, tata);
//		rv = reprez(v, tata);
//
//		if (h[ru] > h[rv]) { tata[rv] = ru; }
//		else {
//
//			tata[ru] = rv;
//			if (h[ru] == h[rv]) { h[rv] = h[rv] + 1; }
//		}
//	}
//	void apm() {
//
//
//		citire_apm();
//
//
//		sort(muchiiCost.begin(), muchiiCost.end(), compare);
//
//		vector<int>tata, h;
//		for (int i = 0; i <= nr_noduri; i++) { //initializam vect de tati si de intaltimi cu 0 pt toata lumea
//
//			tata.push_back(0);
//			h.push_back(0);
//		}
//
//		int nr = 0;//nr de noduri adaugate in prezent la arbore
//
//		int suma_costuri = 0;
//		vector<MuchieCost>muchii_arbore; //creem o noua lista de muchii cu cost pentru noul graf partial format
//		for (int i = 0; i < nr_muchii; i++) {
//
//			int u = muchiiCost[i].get_nod_init();
//			int v = muchiiCost[i].get_nod_final();
//
//
//			if (reprez(u, tata) != reprez(v, tata)) {
//
//				muchii_arbore.push_back(muchiiCost[i]);
//				suma_costuri += muchiiCost[i].get_cost();
//				reuneste(u, v, tata, h);
//				nr++;
//
//				if (nr == nr_noduri - 1) { break; }
//			}
//		}
//
//		ofstream g("apm.out");
//		g << suma_costuri << endl;
//		g << muchii_arbore.size() << endl;
//
//		for (int i = 0; i < muchii_arbore.size(); i++) {
//
//			g << muchii_arbore[i].get_nod_init() << " " << muchii_arbore[i].get_nod_final() << endl;
//		}
//
//		g.close();
//
//	}
//
//
//
//	//disjoint
//
//	void citire_disjoint(vector<MuchieCost>& muchii, int& multimi, int& operatii) {
//
//		ifstream f("disjoint.in");
//		int c, x, y;
//		f >> multimi >> operatii;
//		while (f >> c >> x >> y) {
//
//			muchii.push_back(MuchieCost(x, y, c));
//		}
//		f.close();
//	}
//	void disjoint() {
//
//		vector<MuchieCost>muchii;
//		int multimi, operatii;
//		citire_disjoint(muchii, multimi, operatii);
//
//		vector<int> tata;
//		vector<int> h;
//
//		for (int i = 0; i <= multimi; i++) { //initializam vect de tati si de intaltimi cu 0 pt toata lumea
//
//			tata.push_back(0);
//			h.push_back(0);
//		}
//
//		ofstream g("disjoint.out");
//		for (int i = 0; i < operatii; i++) {
//
//			int u = muchii[i].get_nod_init();
//			int v = muchii[i].get_nod_final();
//
//			if (muchii[i].get_cost() == 1) {
//
//				//int ru = reprez(muchii[i].get_nod_init(), tata);
//				//int rv = reprez(muchii[i].get_nod_final(), tata);
//				reuneste(u, v, tata, h);
//			}
//			else if (muchii[i].get_cost() == 2) {
//
//				if (reprez(u, tata) == reprez(v, tata)) { g << "DA" << "\n"; }
//				else { g << "NU" << "\n"; }
//
//			}
//		}
//
//		g.close();
//	}
//
//
//
//	//dijkstra
//
//	void citire_dijkstra(vector<vector<pair<int, int>>>& lista) {
//
//		ifstream f("dijkstra.in");
//		int c, x, y;
//		f >> nr_noduri >> nr_muchii;
//
//		lista.resize(nr_muchii + 1);
//
//		while (f >> x >> y >> c) {
//
//			lista[x].push_back(make_pair(y, c));
//		}
//
//	}
//	void dijkstra() {
//
//		int infinit = std::numeric_limits<int>::max();
//
//		vector<vector<pair<int, int>>>lista;
//		citire_dijkstra(lista);
//
//
//		vector<int>dist;
//		for (int i = 0; i <= nr_muchii; i++) { dist.push_back(infinit); }
//
//		set<pair<int, int>>set;
//		dist[1] = 0;
//		set.insert(make_pair(0, 1));
//
//		while (!set.empty()) {
//
//			int init = set.begin()->second;
//			set.erase(set.begin());
//
//			for (int i = 0; i < lista[init].size(); i++) {
//
//				int final = lista[init][i].first;
//				int cost = lista[init][i].second;
//
//				if (dist[final] > dist[init] + cost) {
//
//					if (dist[final] != infinit) {
//
//						set.erase(set.find(make_pair(dist[final], final)));
//					}
//
//					dist[final] = dist[init] + cost;
//					set.insert(make_pair(dist[final], final));
//				}
//			}
//		}
//
//		ofstream g("dijkstra.out");
//
//		for (int i = 2; i <= nr_noduri; i++) {
//
//			if (dist[i] != infinit) { g << dist[i] << " "; }
//			else { g << 0 << " "; }
//		}
//
//	}
//
//
//	//bellman-ford
//
//	void citire_bellman_ford(vector<vector<pair<int, int>>>& lista) {
//
//		ifstream f("bellmanford.in");
//		int c, x, y;
//		f >> nr_noduri >> nr_muchii;
//
//		lista.resize(nr_muchii + 1);
//
//		while (f >> x >> y >> c) {
//
//			lista[x].push_back(make_pair(y, c));
//		}
//
//		f.close();
//	}
//	void bellman_ford() {
//
//		vector<vector<pair<int, int>>> lista;
//		citire_bellman_ford(lista);
//
//		int infinit = std::numeric_limits<int>::max();
//		vector<int>dist, aparitii, count;
//		queue<int>coada;
//
//		// to do : initializari din constructori
//		//dist(nr_muchii + 1, infinit)
//		for (int i = 0; i <= nr_noduri; i++) { dist.push_back(0); aparitii.push_back(0); count.push_back(0); }
//		for (int i = 0; i <= nr_noduri; i++) { dist[i] = infinit; }
//
//		dist[1] = 0;
//		coada.push(1);
//		aparitii[1] = 1;
//
//		bool ok = true;
//		while (!coada.empty() && ok == true) {
//
//			int u = coada.front();
//			coada.pop();
//			aparitii[u] = 0;
//
//			for (int i = 0; i < lista[u].size(); i++) {
//
//				int v = lista[u][i].first;
//				int cost = lista[u][i].second;
//
//				if (dist[u] + cost < dist[v]) {
//
//					dist[v] = dist[u] + cost;
//					count[v] = count[v] + 1;
//					if (count[v] == nr_noduri) { ok = false; break; }
//
//					if (aparitii[v] == 0) { coada.push(v), aparitii[v] = 1; }
//				}
//			}
//		}
//
//
//
//		ofstream g("bellmanford.out");
//
//		if (ok == true) {
//
//			for (int i = 2; i <= nr_noduri; i++) {
//
//				g << dist[i] << " ";
//			}
//		}
//		else {
//			g << "Ciclu negativ!";
//		}
//
//		g.close();
//	}
//
//	//royfloyd
//
//	void citire_royfloyd() {
//
//		int infinit = std::numeric_limits<int>::max();
//		ifstream f("royfloyd.in");
//		f >> nr_noduri;
//
//		lista.resize(nr_noduri + 1);
//
//
//		int cost;
//		for (int i = 0; i < nr_noduri; i++) {
//
//			for (int j = 0; j < nr_noduri; j++) {
//
//				lista[i].push_back(infinit);
//				if (i == j) lista[i][i] = 0;
//
//				f >> cost;
//				if (cost != 0) {
//
//					lista[i][j] = cost;
//				}
//			}
//		}
//		f.close();
//	}
//	void royfloyd() {
//
//		citire_royfloyd();
//
//		for (int k = 0; k < nr_noduri; k++) {
//
//			for (int i = 0; i < nr_noduri; i++) {
//
//				for (int j = 0; j < nr_noduri; j++) {
//
//
//					if (lista[i][j] > lista[i][k] + lista[k][j]) {
//
//						lista[i][j] = lista[i][k] + lista[k][j];
//					}
//				}
//			}
//		}
//
//		ofstream g("royfloyd.out");
//
//		for (int i = 0; i < nr_noduri; i++) {
//
//			for (int j = 0; j < nr_noduri; j++) {
//
//				g << lista[i][j] << " ";
//			}
//
//			g << endl;
//		}
//		g.close();
//	}
//
//	//Diametrul unui arbore
//
//	void citire_diametru() {
//
//		ifstream f("darb.in");
//		int x, y;
//		f >> nr_noduri;
//
//		lista.resize(nr_noduri + 1);
//
//		while (f >> x >> y) {
//
//			lista[x].push_back(y);
//			lista[y].push_back(x);
//		}
//		f.close();
//
//		/*for (int i = 1; i <= nr_noduri; i++) {
//
//			cout << i << ": ";
//			for (int j = 0; j < lista[i].size(); j++) {
//
//				cout << lista[i][j] << ", ";
//			}
//			cout << endl;
//		}*/
//	}
//	vector<int> bfs_vizit(int start) {
//
//		queue<int>coada;
//		int x;
//
//		vector<int> vizit(nr_noduri + 1, 0);
//
//		coada.push(start);
//		vizit[start] = 1;
//
//		while (!coada.empty()) {
//
//			x = coada.front();
//			coada.pop();
//
//			for (int i = 0; i < lista[x].size(); i++) {
//
//				if (vizit[lista[x][i]] == 0) {
//
//					coada.push(lista[x][i]);
//					vizit[lista[x][i]] = vizit[x] + 1;
//				}
//			}
//		}
//
//		return vizit;
//
//	}
//	void diametru_arbore() {
//
//		citire_diametru();
//		int random = rand() % nr_noduri + 1;
//
//		vector<int>vizit = bfs_vizit(random);
//
//		int nod_maxi;
//		int dist = 0;
//		for (int i = 1; i <= nr_noduri; i++) {
//
//			if (vizit[i] > dist) {
//
//				dist = vizit[i];
//				nod_maxi = i;
//			}
//		}
//
//		vizit = bfs_vizit(nod_maxi);
//
//		int diam = 0;
//		for (int i = 1; i <= nr_noduri; i++) {
//
//			if (vizit[i] > diam) { diam = vizit[i]; }
//		}
//
//		ofstream g("darb.out");
//		g << diam;
//		g.close();
//	}
//
//
//	//flux maxim
//
//	void citire_flux_maxim(vector<vector<int>>& flux) {
//
//		ifstream f("maxflow.in");
//
//		f >> nr_noduri;
//		f >> nr_muchii;
//
//		lista.resize(nr_noduri + 1);
//
//		flux.resize(nr_noduri + 1, vector<int>(nr_noduri + 1, 0));
//
//		int x, y, cost;
//		while (f >> x >> y >> cost) {
//
//			lista[x].push_back(y);
//			lista[y].push_back(x);
//			flux[x][y] = cost;
//		}
//
//		f.close();
//	}
//	bool bfs_flux(int start, int final, vector<vector<int>>& flux, vector<int>& tata) {
//
//		queue<int>coada;
//		int x;
//
//		vector<int> vizit(nr_noduri + 1, 0);
//
//		coada.push(start);
//		vizit[start] = 1;
//
//		while (!coada.empty()) {
//
//			x = coada.front();
//			coada.pop();
//
//			for (int i = 0; i < lista[x].size(); i++) {
//
//				if (vizit[lista[x][i]] == 0 && flux[x][lista[x][i]] > 0) {
//
//					if (lista[x][i] == final) {
//
//						tata[final] = x;
//						return true;
//					}
//
//					coada.push(lista[x][i]);
//					vizit[lista[x][i]] = 1;
//					tata[lista[x][i]] = x;
//				}
//			}
//		}
//
//		return false;
//	}
//	void flux_maxim() {
//
//		vector<vector<int>> flux;
//		citire_flux_maxim(flux);
//
//		vector<int>tata(nr_noduri + 1, 0);
//
//		int maxi = 0;
//
//		while (bfs_flux(1, nr_noduri, flux, tata) == true) {
//
//			int x = nr_noduri;
//			int mini = 0;
//
//			while (x != 1) {
//
//				if (mini == 0 || flux[tata[x]][x] < mini) { mini = flux[tata[x]][x]; }
//
//				x = tata[x];
//			}
//
//			x = nr_noduri;
//
//			while (x != 1) {
//
//				flux[tata[x]][x] = flux[tata[x]][x] - mini;
//				flux[x][tata[x]] = mini;
//				x = tata[x];
//			}
//
//			maxi += mini;
//		}
//
//		ofstream g("maxflow.out");
//		g << maxi;
//		g.close();
//	}
//
//
//
//	//graf eulerian
//
//	void citire_graf_eulerian(vector<vector<pair<int, int>>>& l) {
//
//		ifstream f("ciclueuler.in");
//		f >> nr_noduri;
//		f >> nr_muchii;
//
//		l.resize(nr_noduri + 1);
//
//		int x, y;
//		int nr_muchie = 0;
//		while (f >> x >> y) {//adaug in lista de muchii pereche (nod_final, nr_muchie)
//
//			nr_muchie++;
//			l[x].push_back(make_pair(y, nr_muchie));
//			l[y].push_back(make_pair(x, nr_muchie));
//		}
//
//		f.close();
//	}
//	void graf_eulerian() {
//
//		vector<vector<pair<int, int>>> l;
//		citire_graf_eulerian(l);
//
//
//		bool ok = true;
//		for (int i = 1; i <= nr_noduri && ok == true; i++) {
//
//			if (l[i].size() % 2 == 1) {
//
//				ok = false;
//			}
//		}
//
//		ofstream g("ciclueuler.out");
//		if (ok == true) {
//
//			vector<int> v; //vect de solutii
//			vector<int> vizit(nr_muchii + 1, 0);//vect de muchii vizitate
//
//			euler(1, l, vizit, v);
//
//			for (int i = 0; i < v.size(); i++) {
//
//				g << v[i] << " ";
//			}
//			g.close();
//		}
//		else {
//
//			g << -1;
//		}
//		g.close();
//	}
//	void euler(int nod_curent, vector<vector<pair<int, int>>>& l, vector<int>& vizit, vector<int>& v) {
//
//		while (l[nod_curent].size() != 0) {
//
//			int vecin = l[nod_curent][l[nod_curent].size() - 1].first;
//			int nr_muchie = l[nod_curent][l[nod_curent].size() - 1].second;
//
//			l[nod_curent].pop_back();
//
//			if (vizit[nr_muchie] == 0) {
//
//				vizit[nr_muchie] = 1;
//				euler(vecin, l, vizit, v);
//			}
//		}
//
//		v.push_back(nod_curent);
//	}
//};
//
//
//int main() {
//
//	Graf* g = new Graf;
//
//	g->graf_eulerian();
//
//	return 0;
//}