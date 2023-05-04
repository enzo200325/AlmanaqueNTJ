// Template de debug simples

void _print() { }
template<typename T, typename... U> void _print(T a, U... b) {
    if(sizeof... (b)){
        cerr << a << ", ";
        _print(b...);
    } else cerr << a;
}
#define debug(x...) cerr << "[" << #x << "] = [", _print(x), cerr << "]" << endl

// #define debug(...)
