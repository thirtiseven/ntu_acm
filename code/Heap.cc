const int N = 1000;

template <class T>
class Heap {
	private:
		T h[N];
		int len;
	public:
		Heap() {
			len = 0;
		}
		inline void push(const T& x) {
			h[++len] = x;
			std::push_heap(h+1, h+1+len, std::greater<T>());
		}
		inline T pop() {
			std::pop_heap(h+1, h+1+len, std::greater<T>());
			return h[len--];
		}
		inline T& top() {
			return h[1];
		}
		inline bool empty() {
			return len == 0;
		}
};