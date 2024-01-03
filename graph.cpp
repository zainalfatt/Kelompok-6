#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

typedef vector<vector<Edge> > Graph;

vector<int> dijkstra(const Graph& graph, int start, int end) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        for (size_t i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i].destination;
            int weight = graph[current][i].weight;

            int tentativeDistance = distance[current] + weight;
            if (tentativeDistance < distance[neighbor]) {
                distance[neighbor] = tentativeDistance;
                pq.push(make_pair(distance[neighbor], neighbor));
            }
        }
    }

    return distance;
}

int main() {
    // Contoh graf
    Graph graph(5); // Inisialisasi dengan 5 elemen (0-4)

    graph[0].push_back(Edge(1, 4));
    graph[0].push_back(Edge(2, 2));
    graph[1].push_back(Edge(3, 5));
    graph[2].push_back(Edge(1, 1));
    graph[2].push_back(Edge(3, 8));

    int start, end;
    cout << "Graph Berarah:Menggunakan Algoritma Dijkstra\n";
    cout << "Masukkan simpul awal (0-4): ";
    cin >> start;

    cout << "Masukkan simpul tujuan (0-4): ";
    cin >> end;

    vector<int> shortestDistances = dijkstra(graph, start, end);

    // Menampilkan jarak terpendek dari simpul awal ke simpul tujuan
    cout << "Jarak terpendek dari simpul " << start << " ke simpul " << end << " adalah: ";
    if (shortestDistances[end] == numeric_limits<int>::max()) {
        cout << "Tidak ada jalur yang menghubungkan simpul tersebut.\n";
    } else {
        cout << shortestDistances[end] << '\n';
    }

    return 0;
}