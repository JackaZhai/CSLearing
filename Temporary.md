1. **求供应工程 J1 零件的供应商号码 SNO：** `Π`<sub>SNO</sub> (`σ`<sub>JNO='J1'</sub>(SPJ))
2. **求供应工程 J1 零件 P1 的供应商号码 SNO：** `Π`<sub>SNO</sub> (`σ`<sub>JNO='J1' AND PNO='P1'</sub>(SPJ))
3. **求供应工程 J1 零件为红色的供应商号码 SNO：** `Π`<sub>SNO</sub> ( (`σ`<sub>JNO='J1'</sub>(SPJ)) `⋈` (`σ`<sub>COLOR='红'</sub>(P)) )
4. **求没有使用天津供应商生产的红色零件的工程号 JNO：** `Π`<sub>JNO</sub>(J) - `Π`<sub>JNO</sub>( (`σ`<sub>CITY='天津'</sub>(S)) `⋈` SPJ `⋈` (`σ`<sub>COLOR='红'</sub>(P)) )
5. **求至少用了供应商 S1 所供应的全部零件的工程号 JNO：** `Π`<sub>JNO, PNO</sub>(SPJ) `÷` `Π`<sub>PNO</sub>(`σ`<sub>SNO='S1'</sub>(SPJ))

