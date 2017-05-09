; woodworking task with 21 parts and 120% wood
; Machines:
;   1 grinder
;   1 glazer
;   1 immersion-varnisher
;   1 planer
;   1 highspeed-saw
;   1 spray-varnisher
;   1 saw
; random seed: 654403

(define (problem wood-prob-s17)
  (:domain woodworking)
  (:objects
    grinder0 - grinder
    glazer0 - glazer
    immersion-varnisher0 - immersion-varnisher
    planer0 - planer
    highspeed-saw0 - highspeed-saw
    spray-varnisher0 - spray-varnisher
    saw0 - saw
    blue black red white mauve green - acolour
    pine beech walnut cherry teak - awood
    p0 p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p15 p16 p17 p18 p19 p20 - part
    b0 b1 b2 b3 b4 b5 b6 b7 - board
    s0 s1 s2 s3 s4 s5 s6 s7 s8 s9 - aboardsize
  )
  (:init
    (grind-treatment-change varnished colourfragments)
    (grind-treatment-change glazed untreated)
    (grind-treatment-change untreated untreated)
    (grind-treatment-change colourfragments untreated)
    (is-smooth smooth)
    (is-smooth verysmooth)
    
    (boardsize-successor s0 s1)
    (boardsize-successor s1 s2)
    (boardsize-successor s2 s3)
    (boardsize-successor s3 s4)
    (boardsize-successor s4 s5)
    (boardsize-successor s5 s6)
    (boardsize-successor s6 s7)
    (boardsize-successor s7 s8)
    (boardsize-successor s8 s9)
    (has-colour glazer0 blue)
    (has-colour glazer0 natural)
    (has-colour glazer0 mauve)
    (has-colour glazer0 green)
    (has-colour glazer0 black)
    (has-colour glazer0 red)
    (has-colour immersion-varnisher0 blue)
    (has-colour immersion-varnisher0 natural)
    (has-colour immersion-varnisher0 mauve)
    (has-colour immersion-varnisher0 black)
    (has-colour immersion-varnisher0 green)
    (has-colour immersion-varnisher0 red)
    (empty highspeed-saw0)
    (has-colour spray-varnisher0 blue)
    (has-colour spray-varnisher0 natural)
    (has-colour spray-varnisher0 mauve)
    (has-colour spray-varnisher0 black)
    (has-colour spray-varnisher0 green)
    (has-colour spray-varnisher0 red)
    (unused p0)
    (goalsize p0 small)
    
    
    
    
    (unused p1)
    (goalsize p1 small)
    
    
    
    
    (unused p2)
    (goalsize p2 medium)
    
    
    
    
    (unused p3)
    (goalsize p3 small)
    
    
    
    
    (unused p4)
    (goalsize p4 medium)
    
    
    
    
    (available p5)
    (colour p5 mauve)
    (wood p5 teak)
    (surface-condition p5 rough)
    (treatment p5 glazed)
    (goalsize p5 small)
    
    
    
    
    (unused p6)
    (goalsize p6 large)
    
    
    
    
    (unused p7)
    (goalsize p7 large)
    
    
    
    
    (unused p8)
    (goalsize p8 large)
    
    
    
    
    (unused p9)
    (goalsize p9 medium)
    
    
    
    
    (unused p10)
    (goalsize p10 large)
    
    
    
    
    (available p11)
    (colour p11 white)
    (wood p11 walnut)
    (surface-condition p11 rough)
    (treatment p11 colourfragments)
    (goalsize p11 small)
    
    
    
    
    (available p12)
    (colour p12 black)
    (wood p12 teak)
    (surface-condition p12 rough)
    (treatment p12 glazed)
    (goalsize p12 small)
    
    
    
    
    (available p13)
    (colour p13 green)
    (wood p13 beech)
    (surface-condition p13 smooth)
    (treatment p13 varnished)
    (goalsize p13 medium)
    
    
    
    
    (unused p14)
    (goalsize p14 large)
    
    
    
    
    (unused p15)
    (goalsize p15 large)
    
    
    
    
    (unused p16)
    (goalsize p16 medium)
    
    
    
    
    (unused p17)
    (goalsize p17 small)
    
    
    
    
    (unused p18)
    (goalsize p18 medium)
    
    
    
    
    (unused p19)
    (goalsize p19 small)
    
    
    
    
    (available p20)
    (colour p20 white)
    (wood p20 beech)
    (surface-condition p20 smooth)
    (treatment p20 colourfragments)
    (goalsize p20 medium)
    
    
    
    
    (boardsize b0 s8)
    (wood b0 beech)
    (surface-condition b0 rough)
    (available b0)
    (boardsize b1 s3)
    (wood b1 beech)
    (surface-condition b1 rough)
    (available b1)
    (boardsize b2 s5)
    (wood b2 teak)
    (surface-condition b2 rough)
    (available b2)
    (boardsize b3 s5)
    (wood b3 cherry)
    (surface-condition b3 rough)
    (available b3)
    (boardsize b4 s7)
    (wood b4 pine)
    (surface-condition b4 rough)
    (available b4)
    (boardsize b5 s1)
    (wood b5 pine)
    (surface-condition b5 rough)
    (available b5)
    (boardsize b6 s9)
    (wood b6 walnut)
    (surface-condition b6 rough)
    (available b6)
    (boardsize b7 s3)
    (wood b7 walnut)
    (surface-condition b7 rough)
    (available b7)
  )
  (:goal
    (and
      (available p0)
      (colour p0 green)
      (wood p0 pine)
      (available p1)
      (colour p1 natural)
      (treatment p1 glazed)
      (available p2)
      (colour p2 natural)
      (surface-condition p2 smooth)
      (available p3)
      (colour p3 natural)
      (treatment p3 glazed)
      (available p4)
      (colour p4 mauve)
      (wood p4 teak)
      (surface-condition p4 verysmooth)
      (available p5)
      (colour p5 black)
      (wood p5 teak)
      (surface-condition p5 smooth)
      (treatment p5 varnished)
      (available p6)
      (colour p6 natural)
      (treatment p6 varnished)
      (available p7)
      (colour p7 red)
      (wood p7 cherry)
      (surface-condition p7 smooth)
      (treatment p7 glazed)
      (available p8)
      (colour p8 green)
      (wood p8 beech)
      (surface-condition p8 verysmooth)
      (treatment p8 varnished)
      (available p9)
      (colour p9 red)
      (wood p9 pine)
      (surface-condition p9 smooth)
      (treatment p9 glazed)
      (available p10)
      (colour p10 mauve)
      (surface-condition p10 smooth)
      (treatment p10 varnished)
      (available p11)
      (colour p11 mauve)
      (wood p11 walnut)
      (surface-condition p11 smooth)
      (treatment p11 varnished)
      (available p12)
      (colour p12 red)
      (wood p12 teak)
      (available p13)
      (colour p13 red)
      (surface-condition p13 verysmooth)
      (treatment p13 varnished)
      (available p14)
      (colour p14 black)
      (wood p14 beech)
      (available p15)
      (colour p15 mauve)
      (wood p15 walnut)
      (available p16)
      (wood p16 beech)
      (treatment p16 glazed)
      (available p17)
      (colour p17 mauve)
      (treatment p17 varnished)
      (available p18)
      (colour p18 red)
      (treatment p18 glazed)
      (available p19)
      (colour p19 blue)
      (surface-condition p19 verysmooth)
      (available p20)
      (surface-condition p20 verysmooth)
      (treatment p20 glazed)
    )
  )
  
)
