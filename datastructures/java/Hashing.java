
public class Hashing<T>{

    public int hashKey(T key) {

        if (String.class.isInstance(key)) {
            return hashString(String.class.cast(key));
        } else if (Integer.class.isInstance(key)) {
            return hashInteger(Integer.class.cast(key));
        } else {
            throw new RuntimeException("cannot cast to other types!");
        }
    }

    private int hashString(String key) {
        final double p = 31;
        final double m = 1e9 + 9;
        double hash_value = 0;
        double p_pow = 1;
        for (char c : key.toCharArray()) {
            hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
            p_pow = (p_pow * p) % m;
        }
        return (int) hash_value;
    }
    private int hashInteger(int key) {
        key = ~key + (key << 15); // key = (key << 15) - key - 1;
        key = key ^ (key >>> 12);
        key = key + (key << 2);
        key = key ^ (key >>> 4);
        key = key * 2057; // key = (key + (key << 3)) + (key << 11);
        key = key ^ (key >>> 16);
        if (key < 0) {
            key *= -1;
        }
        return key;
    }
}
