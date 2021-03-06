/ /   S F M L _ T e s t 2 . c p p   :   D e f i n e s   t h e   e n t r y   p o i n t   f o r   t h e   c o n s o l e   a p p l i c a t i o n .  
 / /  
  
 # i n c l u d e   " s t d a f x . h "  
 # i n c l u d e   < S F M L / G r a p h i c s . h p p >  
 # i n c l u d e   < t i m e . h >  
 u s i n g   n a m e s p a c e   s f ;  
  
 i n t   n u m _ v e r t B o x   =   3 0 ,   n u m _ h o r z B o x   =   2 0 ;  
 i n t   s i z e   =   1 6 ;   / / n u m b e r   o f   p i x e l s  
 i n t   w   =   s i z e   *   n u m _ h o r z B o x ;   / / B a c k g r o u n d   n u m b e r   o f   p i x e l s   i n   w i d t h  
 i n t   l   =   s i z e   *   n u m _ v e r t B o x ;   / / B a c k g r o u n d   n u m b e r   o f   p i x e l s   i n   h e i g h t  
  
 f l o a t   d e l a y   =   . 1 ;  
  
 i n t   d i r e c t i o n ,   d i r e c t i o n 2 ,   s n a k e _ l e n g t h   =   4 ,   s n a k e _ l e n g t h 2   =   4 ;  
  
 / / M a x i m u m   s i z e   o f   S n a k e  
 s t r u c t   S n a k e  
 {  
 	 i n t   x ,   y ;  
 } s [ 1 0 0 ] ;  
  
 s t r u c t   S n a k e 2  
 {  
 	 i n t   x ,   y ;  
 } s 2 [ 1 0 0 ] ;  
  
 s t r u c t   F r u i t  
 {  
 	 i n t   x ,   y ;  
 } F o o d ;  
  
 / / M o v e   r e m a i n i n g   p i e c e s   o f   s n a k e   s [ 1 ]   -   s [ 9 9 ]  
 v o i d   T i c k ( )  
 {  
 	 f o r   ( i n t   i   =   s n a k e _ l e n g t h ;   i   >   0 ;   - - i )  
 	 {  
 	 	 s [ i ] . x   =   s [ i   -   1 ] . x ;  
 	 	 s [ i ] . y   =   s [ i   -   1 ] . y ;  
 	 }  
  
 	 / / H e a d   o f   s n a k e   d e p e n d s   o n   d i r e c t i o n   o f   u s e   s [ 0 ]  
 	 / / U s e r   u p  
 	 i f   ( d i r e c t i o n   = =   3 )  
 	 {  
 	 	 s [ 0 ] . y   - =   1 ;  
 	 }  
 	 / / U s e r   D o w n  
 	 i f   ( d i r e c t i o n   = =   0 )  
 	 {  
 	 	 s [ 0 ] . y   + =   1 ;  
 	 }  
 	 / / U s e r   L e f t  
 	 i f   ( d i r e c t i o n   = =   1 )  
 	 {  
 	 	 s [ 0 ] . x   - =   1 ;  
 	 }  
 	 / / U s e r   u p  
 	 i f   ( d i r e c t i o n   = =   2 )  
 	 {  
 	 	 s [ 0 ] . x   + =   1 ;  
 	 }  
  
 	 / / I f   s n a k e   e a t s   f o o d   i t   s h o u l d   g r o w  
 	 i f   ( ( ( s [ 0 ] . x )   = =   F o o d . x   & &   ( ( s [ 0 ] . y )   = =   F o o d . y ) ) )  
 	 {  
 	 	 / / i n c r e m e n t   s n a k e  
 	 	 s n a k e _ l e n g t h + + ;  
  
 	 	 / / s p e e d   u p   s n a k e  
 	 	 d e l a y   =   d e l a y   /   1 . 3 ;  
  
  
 	 	 / / R a n d o m l y   p l a c e   f o o d   s o m e w h e r e   e l s e  
 	 	 F o o d . x   =   r a n d ( )   %   n u m _ h o r z B o x ;  
 	 	 F o o d . y   =   r a n d ( )   %   n u m _ v e r t B o x ;  
  
 	 }  
  
 	 / / B o u n d a r y   C h e c k i n g   s c r e e n   l o o p   b a c k   o n   o t h e r   s i d e  
 	 / / L E F T   A N D   R I G H T  
 	 i f   ( s [ 0 ] . x   >   n u m _ h o r z B o x )  
 	 	 s [ 0 ] . x   =   0 ;  
 	 i f   ( s [ 0 ] . x   <   0 )  
 	 	 s [ 0 ] . x   =   n u m _ h o r z B o x ;  
  
 	 / / T O P   A N D   B O T T O M  
 	 i f   ( s [ 0 ] . y   >   n u m _ v e r t B o x )  
 	 	 s [ 0 ] . y   =   0 ;  
 	 i f   ( s [ 0 ] . y   <   0 )  
 	 	 s [ 0 ] . y   =   n u m _ v e r t B o x ;  
  
 	 / / C h e c k   i f   g o   o v e r   s n a k e  
 	 f o r   ( i n t   i   =   1 ;   i   <   s n a k e _ l e n g t h ;   i + + )  
 	 {  
 	 	 / / C u t   s n a k e   i n   h a l f   f r o m   p l a c e   e a t e n ,   a n d   s l o w s   i t   d o w n  
 	 	 i f   ( s [ 0 ] . x   = =   s [ i ] . x   & &   s [ 0 ] . y   = =   s [ i ] . y )  
 	 	 {  
 	 	 	 s n a k e _ l e n g t h   =   i ;  
 	 	 	 d e l a y   =   . 1 ;  
 	 	 }  
 	 }  
  
 }  
  
  
 v o i d   T i c k 2 ( )  
 {  
 	 f o r   ( i n t   i   =   s n a k e _ l e n g t h 2 ;   i   >   0 ;   - - i )  
 	 {  
 	 	 s 2 [ i ] . x   =   s 2 [ i   -   1 ] . x ;  
 	 	 s 2 [ i ] . y   =   s 2 [ i   -   1 ] . y ;  
 	 }  
  
 	 / / H e a d   o f   s n a k e   d e p e n d s   o n   d i r e c t i o n   o f   u s e   s [ 0 ]  
 	 / / U s e r   u p  
 	 i f   ( d i r e c t i o n 2   = =   3 )  
 	 {  
 	 	 s 2 [ 0 ] . y   - =   1 ;  
 	 }  
 	 / / U s e r   D o w n  
 	 i f   ( d i r e c t i o n 2   = =   0 )  
 	 {  
 	 	 s 2 [ 0 ] . y   + =   1 ;  
 	 }  
 	 / / U s e r   L e f t  
 	 i f   ( d i r e c t i o n 2   = =   1 )  
 	 {  
 	 	 s 2 [ 0 ] . x   - =   1 ;  
 	 }  
 	 / / U s e r   u p  
 	 i f   ( d i r e c t i o n 2   = =   2 )  
 	 {  
 	 	 s 2 [ 0 ] . x   + =   1 ;  
 	 }  
  
 	 / / I f   s n a k e   e a t s   f o o d   i t   s h o u l d   g r o w  
 	 i f   ( ( ( s 2 [ 0 ] . x )   = =   F o o d . x   & &   ( ( s 2 [ 0 ] . y )   = =   F o o d . y ) ) )  
 	 {  
 	 	 / / i n c r e m e n t   s n a k e  
 	 	 s n a k e _ l e n g t h 2 + + ;  
  
 	 	 / / S p e e d   u p   s n a k e  
 	 	 d e l a y   =   d e l a y   /   1 . 3 ;  
  
 	 	 / / R a n d o m l y   p l a c e   f o o d   s o m e w h e r e   e l s e  
 	 	 F o o d . x   =   r a n d ( )   %   n u m _ h o r z B o x ;  
 	 	 F o o d . y   =   r a n d ( )   %   n u m _ v e r t B o x ;  
  
 	 }  
  
 	 / / B o u n d a r y   C h e c k i n g   s c r e e n   l o o p   b a c k   o n   o t h e r   s i d e  
 	 / / L E F T   A N D   R I G H T  
 	 i f   ( s 2 [ 0 ] . x   >   n u m _ h o r z B o x )  
 	 	 s 2 [ 0 ] . x   =   0 ;  
 	 i f   ( s 2 [ 0 ] . x   <   0 )  
 	 	 s 2 [ 0 ] . x   =   n u m _ h o r z B o x ;  
  
 	 / / T O P   A N D   B O T T O M  
 	 i f   ( s 2 [ 0 ] . y   >   n u m _ v e r t B o x )  
 	 	 s 2 [ 0 ] . y   =   0 ;  
 	 i f   ( s 2 [ 0 ] . y   <   0 )  
 	 	 s 2 [ 0 ] . y   =   n u m _ v e r t B o x ;  
  
 	 / / C h e c k   i f   g o   o v e r   s n a k e  
 	 f o r   ( i n t   i   =   1 ;   i   <   s n a k e _ l e n g t h 2 ;   i + + )  
 	 {  
 	 	 / / C u t   s n a k e   i n   h a l f   f r o m   p l a c e   e a t e n  
 	 	 i f   ( s 2 [ 0 ] . x   = =   s 2 [ i ] . x   & &   s 2 [ 0 ] . y   = =   s 2 [ i ] . y )  
 	 	 {  
 	 	 	 s n a k e _ l e n g t h 2   =   i ;  
 	 	 	 d e l a y   =   . 1 ;  
 	 	 }  
 	 }  
  
 }  
  
 i n t   m a i n ( )  
 {  
 	 s r a n d ( t i m e ( 0 ) ) ;   / / a d d   a p p l e   i n   r a n d o m   p l a c e  
  
 	 R e n d e r W i n d o w   w i n d o w ( V i d e o M o d e ( w ,   l ) ,   " S n a k e   G a m e ! " ) ;  
  
 	 / / T e x t u r e  
 	 T e x t u r e   t 1 ,   t 2 ,   t 3 ,   t 4 ;  
 	 t 1 . l o a d F r o m F i l e ( " i m a g e / w h i t e . p n g " ) ;  
 	 t 2 . l o a d F r o m F i l e ( " i m a g e / r e d . p n g " ) ;  
 	 t 3 . l o a d F r o m F i l e ( " i m a g e / a p p l e . p n g " ) ;  
 	 t 4 . l o a d F r o m F i l e ( " i m a g e / g r e e n . p n g " ) ;  
  
 	 / / S p r i t e   H a s   p h y s i c a l   d i m e n s i o n  
 	 S p r i t e   s p r i t e 1 ( t 1 ) ;  
 	 S p r i t e   s p r i t e 2 ( t 2 ) ;  
 	 S p r i t e   s p r i t e 3 ( t 3 ) ;  
 	 S p r i t e   s p r i t e 4 ( t 4 ) ;  
  
 	 F o o d . x   =   1 0 ;  
 	 F o o d . y   =   1 0 ;  
  
 	 C l o c k   c l o c k ;  
 	 f l o a t   t i m e r   =   0 ;  
  
 	 w h i l e   ( w i n d o w . i s O p e n ( ) )  
 	 {  
 	 	 f l o a t   t i m e   =   c l o c k . g e t E l a p s e d T i m e ( ) . a s S e c o n d s ( ) ;  
 	 	 c l o c k . r e s t a r t ( ) ;  
 	 	 t i m e r   + =   t i m e ;  
  
 	 	 / / A l l o w   u s   t o   c h e c k   w h e n   a   u s e r   d o e s   s o m e t h i n g  
 	 	 E v e n t   e ;  
  
 	 	 / / C h e c k   w h e n   w i n d o w   i s   c l o s i n g  
 	 	 w h i l e   ( w i n d o w . p o l l E v e n t ( e ) )  
 	 	 {  
 	 	 	 i f   ( e . t y p e   = =   E v e n t : : C l o s e d )  
 	 	 	 {  
 	 	 	 	 w i n d o w . c l o s e ( ) ;  
 	 	 	 }  
 	 	 }  
  
 	 	 / / C o n t r o l s   f o r   S n a k e   M o v e m e n t   b y   u s e r  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : U p ) )   d i r e c t i o n   =   3 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : D o w n ) )   d i r e c t i o n   =   0 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : L e f t ) )   d i r e c t i o n   =   1 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : R i g h t ) )   d i r e c t i o n   =   2 ;  
  
 	 	 / / S n a k e   2   M o v e m e n t  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : W ) )   d i r e c t i o n 2   =   3 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : S ) )   d i r e c t i o n 2   =   0 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : A ) )   d i r e c t i o n 2   =   1 ;  
 	 	 i f   ( K e y b o a r d : : i s K e y P r e s s e d ( K e y b o a r d : : D ) )   d i r e c t i o n 2   =   2 ;  
  
  
  
 	 	 i f   ( t i m e r   >   d e l a y )  
 	 	 {  
 	 	 	 t i m e r   =   0 ;   / / R e s e t   t i m e r  
 	 	 	 T i c k ( ) ;   / / M o v e   S n a k e   o n e   s p r i t e   f o w a r d  
 	 	 	 T i c k 2 ( ) ;  
 	 	 }  
  
 	 	 / / D r a w  
 	 	 w i n d o w . c l e a r ( ) ;  
  
 	 	 / / D r a w   B a c k g r o u n d  
 	 	 f o r ( i n t   i   =   0 ;   i   <   n u m _ h o r z B o x ;   i + + )  
 	 	 	 f o r   ( i n t   j   =   0 ;   j   <   n u m _ v e r t B o x ;   j + + )  
 	 	 	 {  
 	 	 	 	 s p r i t e 1 . s e t P o s i t i o n ( i * s i z e ,   j * s i z e ) ;  
 	 	 	 	 w i n d o w . d r a w ( s p r i t e 1 ) ;  
 	 	 	 }  
  
 	 	 / / D r a w   S n a k e  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   s n a k e _ l e n g t h ;   i + + )  
 	 	 {  
 	 	 	 s p r i t e 2 . s e t P o s i t i o n ( s [ i ] . x * s i z e ,   s [ i ] . y * s i z e ) ;  
 	 	 	 w i n d o w . d r a w ( s p r i t e 2 ) ;  
 	 	 }  
  
 	 	 / / D r a w   S n a k e 2  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   s n a k e _ l e n g t h 2 ;   i + + )  
 	 	 {  
 	 	 	 s p r i t e 4 . s e t P o s i t i o n ( s 2 [ i ] . x * s i z e ,   s 2 [ i ] . y * s i z e ) ;  
 	 	 	 w i n d o w . d r a w ( s p r i t e 4 ) ;  
 	 	 }  
  
 	 	 / / D r a w   F r u i t  
 	 	 s p r i t e 3 . s e t P o s i t i o n ( F o o d . x * s i z e ,   F o o d . y * s i z e ) ;  
 	 	 w i n d o w . d r a w ( s p r i t e 3 ) ;  
 	 	  
 	 	 w i n d o w . d i s p l a y ( ) ;  
 	 }  
  
  
 	 r e t u r n   0 ;  
 } 
