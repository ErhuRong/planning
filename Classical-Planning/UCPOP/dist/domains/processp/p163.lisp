(load-start-state
 '(
        (is-a circular-saw1 CIRCULAR-SAW)

	(is-a saw-attachment2 FRICTION-SAW)

        (is-a vise1 VISE)

	(is-a brush1 BRUSH)

	(is-a soluble-oil SOLUBLE-OIL)
	(is-a mineral-oil MINERAL-OIL)

	(is-a part2 PART)
	(material-of part2 COPPER)
	(size-of part2 LENGTH 5)
	(size-of part2 WIDTH 3)
	(size-of part2 HEIGHT 2)
	(surface-finish-side part2 SIDE5 ROUGH-GRIND)
))

(load-goal

	'(exists (<part>) (is-a <part> PART) (surface-finish-side <part> SIDE5 ROUGH-MILL)
)


)