#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cmath>
#include<Windows.h>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<stack>

#define str string
#define float double
#define ll long long
using namespace std;

//有向图
template<class T>
class Graph {
private:
	int node_size;//节点数量
	int size;//the numbers of nodes
	int edges;//边的数量
	struct Node {
		string name;
		T data;
	};
	struct Edge {
		float cost;//边的权值
	};
	//map<string, int> compare_name_node;
	//map<Node, list<Node>> compare_node_list;
	//Node* node;
	vector<Node> node;
	//vector<Node> *node_list;
	map<string, vector<Node>> node_list; //节点名称对邻接表的映射
	map<string, vector<Edge>> edge_list;//同上，对邻接边的映射
	//vector<Edge> *edge_list;
	set<string> node_name_judge;//存储所有拥有的节点的名字的集合

	void error(string error_str) {
		cout << error_str;
		exit(1);
	}
	bool error_remind(string words) {
		cout << words;
		return -1;
	}
	//根据节点名字找下标
	int find_pos(string name) {
		for (int i = 0; i < node.size(); i++) {
			if (name == node[i].name) {
				return i;
			}
		}
		return error_remind("未找到节点名称");
		//return -1;
	}
public:
	int get_size() {
		return node_size;
	}
	//得到A->B的权
	int get_cost(string node_A, string node_B) {
		int pos;
		for (int i = 0; i < node_list[node_A].size(); i++) {
			if (node_list[node_A][i].name == node_B) {
				pos = i;
				return edge_list[node_A][pos].cost;
				break;
			}
		}
		//return error_remind("获得权值时，未找到路径");
		return -1;

	}
	//删除一条路,node_A->node_B
	void delete_edge(string node_A,string node_B){
		if (node_name_judge.count(node_A) == 0 || node_name_judge.count(node_B)==0) {
			cout<<"删除路径时，节点名称错误"<<endl;
			return;
		}
		if (get_cost(node_A, node_B) == -1)
			return;
		int pos;
		int n = node_list[node_A].size();
		for (int i = 0; i < n; i++) {
			if (node_list[node_A][i].name == node_B)
				pos = i;
		}
		node_list[node_A].erase(node_list[node_A].begin()+pos);
		edges--;
	}
	//添加一个节点
	void add_node(string name) {
		if (node_name_judge.count(name) == 1)
			error("插入节点名称重复");
		node_name_judge.insert(name);
		size += 1;
		node_size += 1;
		Node newnode;
		newnode.name = name;
		node.push_back(newnode);
	}
	//添加n个节点
	void add_nodes(int n) {
		string name;
		for (int i = 0; i < n; i++) {
			cin >> name;
			add_node(name);
		}
	}
	//添加一个关系
	void add_one_relationship(string node_A,string node_B,int cost) {
		if (node_name_judge.count(node_A) == 0 || node_name_judge.count(node_B) == 0) {
			cout << "添加关系时，节点名称错误" << endl;
			return;
		}
		//如果已经存在了路径,默认覆盖
		if (get_cost(node_A, node_B) != -1) {
			delete_edge(node_A,node_B);
		}
		Edge new_edge;
		Node new_node;
		new_node.name = node_B;
		new_edge.cost=cost;
		//node_list[compare_name_node[node_A]].push_back(node[compare_name_node[node_B]]);
		//edge_list[compare_name_node[node_A]].push_back(new_edge);
		node_list[node_A].push_back(new_node);
		edge_list[node_A].push_back(new_edge);
		edges++;
	}
	//添加n个关系
	void add_relationship(int edges) {
		cout << "输入关系：" << endl;
		for (int i = 0; i < edges; i++) {
			string node_A, node_B;
			int cost;
			cin >> node_A >> node_B>>cost;
			add_one_relationship(node_A,node_B,cost);
		}
	}
	Graph(int size) {
		node_size = 0;
		Graph::size = 0;
		//node_list = new vector<Node>[size];
		//edge_list = new vector<Edge>[size];
		//for (int i = 0; i < size; i++) {
		//	cout << "输入节点名称" << endl;
		//	Node newnode;
		//	cin >> newnode.name;
		//	node.push_back(newnode);

		//	node_name_judge.insert(newnode.name);
		//	//compare_name_node[newnode.name] = i;//将name映射到线性关系中
		//}
		cout << "输入"<<size<<"个节点名称" << endl;
		add_nodes(size);
		cout << "输入关系数量：";
		int edges;
		cin >> edges;
		add_relationship(edges);
	}
	Graph() {
		size = 0;
		node_size = 0;
		edges = 0;
	}
	
	void show(void) {
		cout << "节点数：" << node_size << endl;;
		cout << "边的数量：" << edges << endl;
		/*for (int i = 0; i < size; i++) {
			for (int j = 0; j < node_list[i].size(); j++) {
				cout << node[i].name << "->";
				cout << node_list[i][j].name<<":";
				cout << edge_list[i][j].cost;
				cout << endl;

			}
		}*/
		cout << "关系：" << endl;
		for (int i = 0; i < node.size(); i++) {
			for (int j = 0; j < node_list[node[i].name].size(); j++) {
				cout << node[i].name << "->";
				cout<< node_list[node[i].name][j].name << ":";
				cout << edge_list[node[i].name][j].cost << endl;
			}
		}
	}
	
	
	//删除节点
	void delete_Node(string name) {
		if (node_name_judge.count(name) == 0) {
			cout << "删除节点时，节点名称错误" << endl;
			return;
		}
		//edges -= edge_list[compare_name_node[name]].size();
		node_name_judge.erase(name);
		node_size -= 1;
		size = node_size;
		edges -= edge_list[name].size();//删除边的数量，被删除节点的出度vector的size
		node_list[name].clear();//删除节点的出度
		edge_list[name].clear();//删除节点的出度边
		//遍历删除入度
		int pos=-1;//待删除节点的坐标
		for (int i = 0; i < node.size(); i++) {
			if (node[i].name == name) {
				pos = i;//记录一下pos,使得程序运行效率更高
				continue;
			}
			for (int j = 0; j < node_list[node[i].name].size(); j++) {
				if (node_list[node[i].name][j].name == name) {
					node_list[node[i].name].erase(node_list[node[i].name].begin() + j);
					edge_list[node[i].name].erase(edge_list[node[i].name].begin() + j);
					edges--;
				}
			}
		}
		//删除这个节点
		//int pos=compare_name_node[name];//待删除节点的坐标
		//如果仍未找到pos
		if (pos == -1) {
			pos = find_pos(name);
		}
		node.erase(node.begin() + pos);//删除节点
		//对映射进行重新映射
		//for (int i = pos; i < node_size; i++) {  //node_size已经减一
		//	compare_name_node[node[i].name] = i;
		//}
		node_list.erase(name);
		edge_list.erase(name);


	}
	~Graph() {
		node_list.clear();
		edge_list.clear();
		node.clear();
		node_name_judge.clear();
	}

	//广度优先遍历
	void BFS(Node& root) {
		queue<Node> Que;
		set<Node> Set;
		Que.push(root);
		Set.insert(root);
		Node Temp;
		while (Que.empty() != 0) {
			Temp = Que.front(); Que.pop();
			string name = Temp.name;
			cout << name << " ";
			for (int i = 0; i < node_list[name].size(); i++) {
				if (Set.count(node_list[name][i]) == 0) {
					Que.push(node_list[name][i]);
				}
			}
		}
	}

	void BFS(string name) {
		queue<Node> Que;
		set<string> Set;
		if (node_name_judge.count(name) == 0) {
			cout << "BFS，根节点名称错误" << endl;
			return;
		}
		Node root;
		for (int i = 0; i < node.size(); i++) {
			if (name == node[i].name) {
				root = node[i];
				break;
			}
		}
		//if (root == NULL)
			//error("节点名称异常");
		Que.push(root);
		Set.insert(name);
		Node Temp;
		while (Que.empty() == 0) {
			Temp = Que.front(); Que.pop();
			string name = Temp.name;
			cout << name << " ";
			for (int i = 0; i < node_list[name].size(); i++) {
				if (Set.count(node_list[name][i].name) == 0) {
					Que.push(node_list[name][i]);
					Set.insert(node_list[name][i].name);
				}
			}
		}
		cout << endl;
	}
	//深度优先遍历
	void DFS_func(Node root, set<string>& Set) {
		if (Set.count(root.name)) return;
		else cout << root.name << " ";
		Set.insert(root.name);
		for (int i = 0; i < node_list[root.name].size(); i++) {
			if (Set.count(node_list[root.name][i].name)) {
				continue;
			}
			else {
				DFS_func(node_list[root.name][i], Set);

			}

		}
	}
	void DFS(string name) {
		if (node_name_judge.count(name) == 0) {
			cout << "DFS，根节点名称错误" << endl;
			return;
		}
		set<string> Set;
		int root_pos = find_pos(name);
		DFS_func(node[root_pos], Set);
		cout << endl;
	}
	//普利姆最小生成树
	void Prim(string root) {
		if (node_name_judge.count(root) == 0) {
			error_remind("普利姆最小生成树，root节点名称错误");
			return;
		}
		vector<Edge> selecting_edges;//候选边
		vector<Node> selecting_nodes;//候选节点

		int root_pos = find_pos(root);
		Graph min_tree;//最小生成树
		//把这个树的所有节点都添加上，不一定都要用（非连通图）
		for (int i = 0; i < node.size();i++) {
			min_tree.add_node(node[i].name);
		}
		//第一次更新mintree
		for (int i = 0; i < node.size(); i++) {
			if (i == root_pos)  //遍历结果正好是第一个节点
				continue;
			int adding_cost;//待添加的关系权
			adding_cost = get_cost(root,node[i].name);
			//如果两点之间没有路径，用M表示无穷远
			if (adding_cost == -1) {
				adding_cost = 99999;
			}
			min_tree.add_one_relationship(root,node[i].name,adding_cost);

			selecting_nodes.push_back(node_list[root][i]);
			selecting_edges.push_back(edge_list[root][i]);
		}
	}
	//最小生成树
	void min_tree(string root) {
		if (node_name_judge.count(root) == 0) {
			error_remind("最小生成树，root节点名称错误");
			return;
		}
		struct selecting_edge_and_node{
			string this_name;
			int cost;
			string will_be_selected_name;
		};
		Graph min_tree;
		//把这个树的所有节点都添加上，不一定都要用（非连通图）
		for (int i = 0; i < node.size(); i++) {
			min_tree.add_node(node[i].name);
		}
		vector<selecting_edge_and_node> selecting;//候选边集
		//int root_pos = find_pos(root);
		//第一次更新侯选边
		for (int i = 0; i < node_list[root].size(); i++) {
			if (node_list[root][i].name == root)
				continue;
			selecting_edge_and_node one_selecting_edge;
			one_selecting_edge.this_name = root;
			one_selecting_edge.cost = edge_list[root][i].cost;
			//one_selecting_edge.cost = get_cost(root,node[i].name);
			one_selecting_edge.will_be_selected_name = node_list[root][i].name;
			selecting.push_back(one_selecting_edge);
		}
		set<string> selected_node_name;//已经被选的边的集合，用于判断
		selected_node_name.insert(root);
		while (selecting.size() != 0) {
			//先去除在侯选边中，那些出度到已经选择的节点，
			for (int i = 0; i < selecting.size(); i++) {
				if (selected_node_name.count(selecting[i].will_be_selected_name)) {
					selecting.erase(selecting.begin() + i);
				}
			}
			if (selecting.size() == 0) {
				break;
			}
			int min_struct_pos=0;//最小的路径在侯选边中的坐标
			int min_cost = selecting[0].cost;
			//找最小
			for (int i = 1; i < selecting.size(); i++) {
				//感觉判断-1有点多余
				if (min_cost > selecting[i].cost&&selecting[i].cost!=-1) {
					min_cost = selecting[i].cost;
					min_struct_pos = i;
				}
			}
			string be_selected_name = selecting[min_struct_pos].will_be_selected_name;
			min_tree.add_one_relationship(selecting[min_struct_pos].this_name,be_selected_name,selecting[min_struct_pos].cost);
			//更新侯选边
			//先删除,删除侯选边中已经选择的边
			selecting.erase(selecting.begin() + min_struct_pos);
			//再更新
			selected_node_name.insert(be_selected_name);
			for (int i = 0; i < node_list[be_selected_name].size(); i++) {
				/*if (selected_node_name.count(node_list[be_selected_name][i].name))
					continue;*/
				selecting_edge_and_node newone;
				newone.this_name = be_selected_name;
				newone.cost = edge_list[be_selected_name][i].cost;
				newone.will_be_selected_name = node_list[be_selected_name][i].name;
				selecting.push_back(newone);
			}
		}
		min_tree.show();
	}
	//最短路径(迪克特拉斯算法)
	void min_road(string start,string end) {
		//路径，到point的路径，cost为权值
		struct road {
			//string begin;
			string point;
			double cost;
			vector<string> experience;//中间经过的节点
		};
		//map<string, road> selecting_node;
		vector<road> selecting;//既是候选，也是已选路径
		set<string> selected_node;//已经选到的节点,拿过出度的节点
		selected_node.insert(start);
		//初始化
		for (int i = 0; i < node_list[start].size(); i++) {
			road a_road;
			//a_road.begin = start;
			a_road.point = node_list[start][i].name;
			a_road.cost = edge_list[start][i].cost;
			selecting.push_back(a_road);
			//selecting_node[node_list[start][i].name] = a_road;
		}
		//找最小
		int min_road_pos = 0;//当前最小路径在selecting中的下标,选择的结果一定是第一个节点的出度，因此不用特判回路
		double min_cost = selecting[0].cost;
		string point_name = selecting[0].point;//把name拿出来
		vector<string> min_road_experience=selecting[min_road_pos].experience;//把experience拿出来,这些全部拿出来，因为待会第一件事就是删除这个最短路径
		for (int i = 1; i < selecting.size(); i++) {
			if (selecting[i].cost < min_cost) {
				min_road_pos = i;
				min_cost = selecting[i].cost;
				min_road_experience = selecting[i].experience;
				point_name = selecting[i].point;
			}
		}
		//循环截至条件，到end的路为最小
		while (selecting[min_road_pos].point!=end) {
			selecting.erase(selecting.begin()+min_road_pos);//删除这个最短路径
			//string point_name = selecting[min_road_pos].point;
			//将选择到的节点加入到已选边中，
			selected_node.insert(point_name);
			//更新候选边，遍历
			for (int i = 0; i < node_list[point_name].size(); i++) {
				if (selected_node.count(node_list[point_name][i].name))
					continue;
				road a_road;
				a_road.experience = min_road_experience;//先把vector复制过来再push
				a_road.experience.push_back(point_name);
				a_road.point = node_list[point_name][i].name;
				a_road.cost = edge_list[point_name][i].cost + min_cost;
				//selecting.push_back(a_road);
				//寻找相同的point，并比较cost大小更新
				bool judge = 0;//用于判断这条边的point在selecting中是否已经具有
				for (int j = 0; j < selecting.size(); j++) {
					if (selecting[j].point == node_list[point_name][i].name) {
						if (selecting[j].cost > min_cost + edge_list[point_name][i].cost) {
							selecting.erase(selecting.begin() + j);//删除大边，删除原来的边
							selecting.push_back(a_road);//加上刚刚选的边
						}
						//juddge=1 找到了同名的，如果同名的这个cost比原来的大，那就不做任何事
						judge = 1;
						break;//只可能找到一条边同名，或者说同终点，因此break掉
					}
				}
				//如果上面的for循环没有找到相同的point，则默认push到selecting中
				if (judge == 0) {
					selecting.push_back(a_road);
				}
				
			}
			//更新最小边
			min_road_pos = 0;
			min_cost = selecting[0].cost;
			for (int i = 1; i < selecting.size(); i++) {
				if (selecting[i].cost < min_cost) {
					min_road_pos = i;
					min_cost = selecting[i].cost;
				}
			}
			point_name = selecting[min_road_pos].point;
			min_road_experience = selecting[min_road_pos].experience;

		}
		cout << start<<"->";
		for (int i = 0; i < selecting[min_road_pos].experience.size(); i++) {
			cout << selecting[min_road_pos].experience[i] << "->";
		}
		cout << end<<" 总的cost:"<<min_cost<<endl;
	}
	//求节点的入度
	int get_in(string name) {
		int ans=0;
		for (int i = 0; i < node_size; i++) {
			if (node[i].name == name)
				continue;
			for (int j = 0; j < node_list[node[i].name].size(); j++) {
				if (node_list[node[i].name][j].name == name) {
					ans++;
				}
			}
		}

		return ans;
	}
	//拓扑排序
	void topology() {
		Graph help;
		help = *this;
		vector<Node> help_node = node;
		queue<string> ans;
		int degrees = 0;
		int count = 0;
		do {
			for (int i = 0; i < help.get_size(); i++) {
				if (help.get_in(help_node[i].name) == degrees) {
					ans.push(help_node[i].name);
					count++;
					degrees++;
				}
			}
			string ANS = ans.front();
			cout << ANS;
			help.delete_Node(ANS);
			ans.pop();
		} while (!ans.empty());
	}
};

int main() {
	int n;
	cout << "输入节点数目" << endl;
	cin >> n;
	Graph<int> graph(n);
	//graph.show();
	//graph.delete_Node("A");
	//cout << "删除A节点之后" << endl;
	//graph.show();
	//cout << "广度优先遍历:" << endl;
	//graph.BFS("A");

	//cout << "深度优先遍历：" << endl;
	//graph.DFS("A");
	//cout << "最小生成树" << endl;
	//graph.min_tree("A");
	/*for (char i = 'B'; i <= 'E'; i++) {
		cout << "最短路径，A->"<<i << endl;
		string node=" ";
		node[0] = i;
		graph.min_road("A", node);
	}*/
	graph.topology();
	
	
	return 0;
}
