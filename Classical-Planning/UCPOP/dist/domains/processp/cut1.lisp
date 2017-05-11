(load-start-state
 '(
        (is-a milling-machine1 MILLING-MACHINE)

        (is-a vise1 VISE)

	(is-a milling-cutter1 PLAIN-MILL)
	(is-a milling-cutter2 END-MILL)

	(is-a brush1 BRUSH)

	(is-a soluble-oil SOLUBLE-OIL)
	(is-a mineral-oil MINERAL-OIL)

	(is-a part2 PART)
	(material-of part2 COPPER)
	(size-of part2 LENGTH 5)
	(size-of part2 WIDTH 3)
	(size-of part2 HEIGHT 3)
))

(load-goal

	'(exists (<part>) (is-a <part> PART) (and 
	      (size-of <part> LENGTH 4)
	      (size-of <part> HEIGHT 1)
	      (size-of <part> WIDTH 2)
	 )
)


)