

typedef struct miopunto *punto;

/**
 * creapunto: accetta in ingresso due coordinate di punto e restituisce un punto
 * Sintattica:
 *     creapunto(float,float) -> punto
 * Semantica:
 *     creapunto(x,y) -> p
 */
punto creapunto(float x, float y); 

/**
 * ascissa: accetta in ingresso un punto e ne restituisce l'ascissa
 * Sintattica:
 *    ascissa(punto) -> float
 * Semantica:
 *    ascissa(p) -> x
 *       Post: valore float x dell'ascissa di p
 */
float ascissa(punto p);
/**
 * ordinata: accetta in ingresso un punto e ne restituisce l'ordinata
 * Sintattica:
 *    ordinata(punto) -> float
 * Semantica:
 *    ordinata(p) -> x
 *       Post: valore float x dell'ordinata di p
 */
float ordinata(punto p);

/**
 * distanza: accetta in ingresso due punti e ne restituisce la distanza
 *    utilizzando il teorema di pitagora
 * Sintattica:
 *    distanza(punto,punto) -> float
 * Semantica:
 *    distanza(p1,p2) -> d
 *       Post: d = radice quadrata(p1*p1 + p2*p2)
 */
float distanza(punto p1, punto p2);

