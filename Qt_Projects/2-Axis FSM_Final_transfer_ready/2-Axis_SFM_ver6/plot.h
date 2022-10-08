#include <qwt_plot.h>
#include <qwt_interval.h>
#include <qwt_system_clock.h>
#include <qwt_scale_draw.h>
#include <qwt_plot_zoomer.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_curve.h>

#include "structDef.h"

class QwtPlotCurve;
class QwtPlotMarker;
class QwtPlotDirectPainter;

class plotZoomer: public QwtPlotZoomer
{
public:
    plotZoomer( QWidget *canvas ):QwtPlotZoomer( canvas )
    {
        setTrackerMode( AlwaysOn );
    }

    virtual QwtText trackerText( const QPoint &pos ) const
    {
        QColor bg( Qt::white );
        bg.setAlpha( 200 );
        QwtText text;

        const QwtPlotItemList& itmList = this->plot()->itemList();
        for ( QwtPlotItemIterator it = itmList.begin();it != itmList.end(); ++it )
        {
            if ( ( *it )->rtti() == QwtPlotItem::Rtti_PlotCurve )
            {
                QwtPlotCurve *c = static_cast<QwtPlotCurve *>( *it );

                double d;
                int idx = c->closestPoint( pos, &d );
                if (d < 5)
                {
                    text = QwtPlotZoomer::trackerTextF(c->sample(idx));
                }
           }
        }
        text.setBackgroundBrush( QBrush( bg ) );
        return text;
    }
};

#if 0
class MyScaleDraw: public QwtScaleDraw
{
public:
    MyScaleDraw()
    {
        setTickLength( QwtScaleDiv::MajorTick, 10 );
        setTickLength( QwtScaleDiv::MinorTick, 2 );
        setTickLength( QwtScaleDiv::MediumTick, 0 );

        setLabelRotation( 0 );
        setLabelAlignment( Qt::AlignLeft | Qt::AlignVCenter );
        setSpacing( 10 );
    }
/*
    virtual QwtText label( double value ) const
    {
        QwtText h=QwtText(QString::number(value*info_Inspection.scanInterval.toFloat()));
        return h;
    }
    */
};
#endif
class Plot: public QwtPlot
{
    Q_OBJECT

public:
    Plot(QWidget * = NULL, bool vMarkEnArg=false , QString title=NULL, structSetting *settingInfoPtrArg=NULL);
    virtual ~Plot();



public Q_SLOTS:
    //void UpdateCurve(void *y_pt, bool isShort=0, bool vertMarkerEnable=0, QString Title=NULL);
    void UpdateCurve(float *y_pt, QString Title=NULL, float *x_pt=NULL);
    void updateVertMarker(int markerPos);
    void updateAxisScale();
    void initPlot();
    void decalreMemory();
    void setPlotAttributes(QString title, QString yTitle, double yMin, double yMax,QString xTitle, double xMin, double xMax);
    void UpdatePlot();


protected:

private:
    QwtPlotMarker *d_origin,*vertMarker;
    QwtPlotCurve *d_curve;
    bool replotRequested;
    QwtPlotDirectPainter *d_directPainter;
    structSetting *settingInfoPtr;
    double* x_pt_d_loc;
    double* y_pt_d_loc;
    bool vMarkEn;
    plotZoomer* zoomerV;
    QwtPlotPanner* pannerV;
    QwtPlotMagnifier* magnifierV;
};
